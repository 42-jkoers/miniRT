# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jkoers <jkoers@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/05 15:36:08 by jkoers        #+#    #+#                  #
#    Updated: 2021/01/17 13:35:42 by jkoers        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME      		= miniRT

CC          	= gcc
CFLAGS      	= -Wall -Wextra -Werror -Wuninitialized -O3
# CFLAGS			= -Wall -Wextra -Wuninitialized -O0 # debug

SRCEXT      	= c
SRCDIR      	= src
HEADERDIR		= include
OBJEXT      	= o
BUILDDIR    	= obj

SETTINGS		= settings.h
LIBDIR			= lib
ifeq ($(shell uname),Linux)
MLXDIR			= minilibx-linux/
LINKSRC			= -lm -lpthread
LINKS			= $(LINKSRC) -L$(LIBDIR)/$(MLXDIR) -lmlx -lXext -lX11
LIBS			= $(LIBDIR)/minilibx-linux/libmlx.a \
				  $(LIBDIR)/libft/bin/libft.a
else
MLXDIR			= minilibx_mms_20200219/
LINKSRC			=
LINKS			= -L$(LIBDIR)/$(MLXDIR) -lmlx
LIBS			= $(LIBDIR)/libft/bin/libft.a libmlx.dylib
endif

HEADERS			= $(shell find $(HEADERDIR) -type f -name '*.h')
include sources.mk
OBJ	= $(foreach src,$(SRC),$(BUILDDIR)/$(notdir $(src:.$(SRCEXT)=.$(OBJEXT))))

STARTGREEN		= @echo "\033[38;2;0;255;0m\c"
RESETCOLOR		= @echo "\033[0m\c"
TESTRT			= rt/standard.rt

VPATH = $(shell find $(SRCDIR) -type d | tr '\n' ':' | sed -E 's/(.*):/\1/')

all:
ifneq ($(shell grep $(SETTINGS) -e '\# define BONUS.*'),\# define BONUS 0)
	sed -i 's/# define BONUS.*/# define BONUS 0/' $(SETTINGS)
endif
	make -j4 $(NAME)

bonus:
ifneq ($(shell grep $(SETTINGS) -e '\# define BONUS.*'),\# define BONUS 1)
	sed -i 's/# define BONUS.*/# define BONUS 1/' $(SETTINGS)
endif
	make -j4 $(NAME)

$(NAME): $(BUILDDIR)/ $(OBJ) $(HEADERS) $(LIBS) $(SETTINGS)
	$(CC) $(CFLAGS) -I$(HEADERDIR) $(BUILDDIR)/*.$(OBJEXT) -o $(NAME) \
$(LIBS) $(LINKS)

# sources

$(BUILDDIR)/%.$(OBJEXT): %.$(SRCEXT) $(HEADERS) $(SETTINGS)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $< -o $(BUILDDIR)/$(notdir $@) $(LINKSRC)

# libs

ifeq ($(shell uname),Linux)
$(LIBDIR)/minilibx-linux/libmlx.a:
	$(MAKE) -C $(LIBDIR)/minilibx-linux/
else
libmlx.dylib:
	make -C $(LIBDIR)/minilibx_mms_20200219/
	cp $(LIBDIR)/minilibx_mms_20200219/libmlx.dylib .
endif

$(LIBDIR)/libft/bin/libft.a:
	$(MAKE) -C $(LIBDIR)/libft/

clean:
	make -C $(LIBDIR)/minilibx-linux/ clean
	make -C $(LIBDIR)/libft/ clean
ifneq ($(BUILDDIR),.)
	/bin/rm -rf $(BUILDDIR)/
endif

fclean:
	$(MAKE) clean
# make -C $(LIBDIR)/minilibx-linux/ fclean
	make -C $(LIBDIR)/libft/ fclean
	/bin/rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

findsources:
	echo "# SRC = find src/ -name \"\*.c\" -exec echo \"\{\} \\\\\" \\\;" \
> sources.mk
	echo "SRC = \\" >> sources.mk
	find src/ -name "*.c" -exec echo "{} \\" \; >> sources.mk

silent:
	@$(MAKE) > /dev/null

eval:
	$(MAKE) > /dev/null
	@echo ""
	find eval/ -name "*.rt" -exec echo {} \; -exec ./$(NAME) {} --save \; \
-exec mv scene.bmp {}.bmp \;

evalclean:
	find eval/ -name "*.bmp" -exec rm {} \;

standard:
	@$(MAKE) > /dev/null
	@./$(NAME) $(TESTRT) --save
	@while inotifywait -qq -e close_write $(TESTRT); do \
$(MAKE) > /dev/null && ./$(NAME) $(TESTRT) --save; done

rt:
	@$(MAKE) > /dev/null
	@find rt/ -name "*.rt" -exec echo {} \; \
-exec ./$(NAME) {} --save \; \
-exec mv scene.bmp {}.bmp \; \
-exec echo "" \;

rttest:
	@$(MAKE) > /dev/null
	@find rt_test/ -name "*.rt" -exec echo {} \; \
-exec ./$(NAME) {} --save \; \
-exec mv scene.bmp {}.bmp \; \
-exec echo "" \;


.PHONY: all clean fclean re silent eval evalclean rt rtall

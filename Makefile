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
CFLAGS      	= -Wall -Wextra -Wuninitialized -O3

SRCEXT      	= c
SRCDIR      	= src
HEADERDIR		= include
OBJEXT      	= o
BUILDDIR    	= obj

SETTINGS		= settings.h
LIBDIR			= lib
LINKS			= -L$(LIBDIR)/minilibx-linux -lmlx -lXext -lX11 -lm -lpthread
SOURCELINKS		= -lm -lpthread
LIBS			= $(LIBDIR)/minilibx-linux/libmlx.a \
				  $(LIBDIR)/libft/bin/libft.a
HEADERS			= $(shell find $(HEADERDIR) -type f -name '*.h')
SRC     		= $(shell find $(SRCDIR) -name "*.$(SRCEXT)" -exec basename {} \;)
OBJ				= $(addprefix $(BUILDDIR)/, $(SRC:.$(SRCEXT)=.$(OBJEXT)))
STARTGREEN		= @echo "\033[38;2;0;255;0m\c"
RESETCOLOR		= @echo "\033[0m\c"

VPATH = $(shell find $(SRCDIR) -type d | tr '\n' ':' | sed -r 's/(.*):/\1/')
# main

all:
	$(MAKE) -j4 $(NAME)

$(NAME): $(BUILDDIR)/ $(OBJ) $(HEADERS) $(LIBS) $(SETTINGS)
	$(CC) $(CFLAGS)-I$(HEADERDIR) $(BUILDDIR)/*.$(OBJEXT) -o $(NAME) $(LIBS) $(LINKS)

# sources

$(BUILDDIR)/%.$(OBJEXT): %.$(SRCEXT) $(HEADERS) $(SETTINGS)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $< -o $(BUILDDIR)/$(notdir $@) $(SOURCELINKS)

# libs

$(LIBDIR)/minilibx-linux/libmlx.a:
	$(MAKE) -C $(LIBDIR)/minilibx-linux/

$(LIBDIR)/libft/bin/libft.a:
	$(MAKE) -C $(LIBDIR)/libft/

clean:
# make -C $(LIBDIR)/minilibx-linux/ clean
	make -C $(LIBDIR)/libft/ clean
ifneq "$(BUILDDIR)" "."
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

sync:
	cp -rf ~/GitHub/libft/ $(LIBDIR)
	rm -rf $(LIBDIR)/libft/.git/
	make -C $(LIBDIR)/libft/

dev:
	make > /dev/null && valgrind -q ./miniRT

rt:
	@$(MAKE) > /dev/null
	@./miniRT rt/standard.rt --save
	@while inotifywait -qq -e close_write rt/standard.rt; do make > /dev/null && ./miniRT rt/standard.rt --save; done

rtall:
	@$(MAKE) > /dev/null
	@find rt/ -name "*.rt" -exec echo {} \; -exec ./miniRT {} --save \; -exec mv scene.bmp renders/{}.bmp \;

silent:
	@$(MAKE) > /dev/null

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

.PHONY: all clean fclean re sync rt

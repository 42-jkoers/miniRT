# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jkoers <jkoers@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/05 15:36:08 by jkoers        #+#    #+#                  #
#    Updated: 2020/12/20 22:43:44 by jkoers        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME      		= miniRT

CC          	= gcc
CFLAGS      	= -Wall -Wextra -Wuninitialized -O2

SRCEXT      	= c
SRCDIR      	= src
HEADERDIR		= include
OBJEXT      	= o
BUILDDIR    	= obj

LIBDIR			= lib
LINKS			= -L$(LIBDIR)/minilibx-linux -lmlx -lXext -lX11
LIBS			= $(LIBDIR)/minilibx-linux/libmlx.a \
				  $(LIBDIR)/ft_printf/libftprintf.a \
				  $(LIBDIR)/libft/bin/libft.a
HEADERS			= $(shell find $(HEADERDIR) -type f -name *.h)
SOURCES     	= $(shell find $(SRCDIR)/ -type f -name *.$(SRCEXT))
OBJECTS     	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,\
				  $(SOURCES:$(SRCEXT)=$(OBJEXT)))
STARTGREEN		= @echo "\033[38;2;0;255;0m\c"
RESETCOLOR		= @echo "\033[0m\c"

# main

all: $(NAME)

$(NAME): $(BUILDDIR)/ $(OBJECTS) $(HEADERS) $(LIBS)
	$(CC) $(CFLAGS) -I. -I$(HEADERDIR) $(BUILDDIR)/*.$(OBJEXT) -o $(NAME) $(LIBS) $(LINKS)

# libs

$(LIBDIR)/minilibx-linux/libmlx.a:
	make -C $(LIBDIR)/minilibx-linux/

$(LIBDIR)/ft_printf/libftprintf.a:
	make -C $(LIBDIR)/ft_printf/

$(LIBDIR)/libft/bin/libft.a:
	make -C $(LIBDIR)/libft/

# sources

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT) $(HEADERS)
	$(CC) $(CFLAGS) -I. -I$(HEADERDIR) -c $< -o $@

clean:
	make -C $(LIBDIR)/minilibx-linux/ clean
	make -C $(LIBDIR)/ft_printf/ clean
	make -C $(LIBDIR)/libft/ clean
ifneq "$(BUILDDIR)" "."
	/bin/rm -rf $(BUILDDIR)/
endif

fclean: clean
# make -C $(LIBDIR)/minilibx-linux/ fclean
	make -C $(LIBDIR)/ft_printf/ fclean
	make -C $(LIBDIR)/libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

.PHONY: all clean fclean re

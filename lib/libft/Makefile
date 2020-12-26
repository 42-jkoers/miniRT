# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: joppe <joppe@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/23 17:53:14 by jkoers        #+#    #+#                  #
#    Updated: 2020/12/26 19:25:48 by jkoers        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME      		= libft

CC          	= gcc
CFLAGS      	= -Wall -Wextra -Werror -Wuninitialized

SRCEXT      	= c
SRCDIR      	= src
HEADERDIR		= include
OBJEXT      	= o
BUILDDIR    	= obj
BINDIR			= bin
HEADER			= include/libft.h include/internal.h

TESTNAME		= testor
UNITTEST		= test/test_ft_split_file.c

SOURCES			= $(SRCDIR)/ft_abs.c \
				  $(SRCDIR)/ft_arr_voidp.c \
				  $(SRCDIR)/ft_arr_voidp2.c \
				  $(SRCDIR)/ft_atoi.c \
				  $(SRCDIR)/ft_bzero.c \
				  $(SRCDIR)/ft_calloc.c \
				  $(SRCDIR)/ft_free_2d.c \
				  $(SRCDIR)/ft_get_next_line.c \
				  $(SRCDIR)/ft_get_next_line2.c \
				  $(SRCDIR)/ft_includes.c \
				  $(SRCDIR)/ft_isalnum.c \
				  $(SRCDIR)/ft_isalpha.c \
				  $(SRCDIR)/ft_isascii.c \
				  $(SRCDIR)/ft_isdigit.c \
				  $(SRCDIR)/ft_isprint.c \
				  $(SRCDIR)/ft_isspace.c \
				  $(SRCDIR)/ft_itoa.c \
				  $(SRCDIR)/ft_lstadd_back.c \
				  $(SRCDIR)/ft_lstadd_front.c \
				  $(SRCDIR)/ft_lstclear.c \
				  $(SRCDIR)/ft_lstdelone.c \
				  $(SRCDIR)/ft_lstiter.c \
				  $(SRCDIR)/ft_lstlast.c \
				  $(SRCDIR)/ft_lstmap.c \
				  $(SRCDIR)/ft_lstnew.c \
				  $(SRCDIR)/ft_lstpush_back.c \
				  $(SRCDIR)/ft_lstpush_front.c \
				  $(SRCDIR)/ft_lstshift.c \
				  $(SRCDIR)/ft_lstsize.c \
				  $(SRCDIR)/ft_max.c \
				  $(SRCDIR)/ft_max_u.c \
				  $(SRCDIR)/ft_memccpy.c \
				  $(SRCDIR)/ft_memchr.c \
				  $(SRCDIR)/ft_memcmp.c \
				  $(SRCDIR)/ft_memcpy.c \
				  $(SRCDIR)/ft_memdup.c \
				  $(SRCDIR)/ft_memmove.c \
				  $(SRCDIR)/ft_memset.c \
				  $(SRCDIR)/ft_numlen.c \
				  $(SRCDIR)/ft_numlen_u.c \
				  $(SRCDIR)/ft_numtobase.c \
				  $(SRCDIR)/ft_numtobase_u.c \
				  $(SRCDIR)/ft_numtohexstr_precision_u.c \
				  $(SRCDIR)/ft_numtohexstr_u.c \
				  $(SRCDIR)/ft_numtostr.c \
				  $(SRCDIR)/ft_numtostr_precision.c \
				  $(SRCDIR)/ft_numtostr_precision_u.c \
				  $(SRCDIR)/ft_numtostr_u.c \
				  $(SRCDIR)/ft_padend.c \
				  $(SRCDIR)/ft_padstart.c \
				  $(SRCDIR)/ft_putchar_fd.c \
				  $(SRCDIR)/ft_putendl_fd.c \
				  $(SRCDIR)/ft_putnbr_fd.c \
				  $(SRCDIR)/ft_putstr.c \
				  $(SRCDIR)/ft_putstr_fd.c \
				  $(SRCDIR)/ft_realloc.c \
				  $(SRCDIR)/ft_split.c \
				  $(SRCDIR)/ft_split_file.c \
				  $(SRCDIR)/ft_split_length.c \
				  $(SRCDIR)/ft_split_or.c \
				  $(SRCDIR)/ft_strcat.c \
				  $(SRCDIR)/ft_strchr.c \
				  $(SRCDIR)/ft_strcmp.c \
				  $(SRCDIR)/ft_strcpy.c \
				  $(SRCDIR)/ft_strdup.c \
				  $(SRCDIR)/ft_strjoin.c \
				  $(SRCDIR)/ft_strlcat.c \
				  $(SRCDIR)/ft_strlcpy.c \
				  $(SRCDIR)/ft_strlen.c \
				  $(SRCDIR)/ft_strmapi.c \
				  $(SRCDIR)/ft_strncat.c \
				  $(SRCDIR)/ft_strncmp.c \
				  $(SRCDIR)/ft_strncpy.c \
				  $(SRCDIR)/ft_strndup.c \
				  $(SRCDIR)/ft_strndup_unsafe.c \
				  $(SRCDIR)/ft_strnstr.c \
				  $(SRCDIR)/ft_strrchr.c \
				  $(SRCDIR)/ft_strset.c \
				  $(SRCDIR)/ft_strtolower.c \
				  $(SRCDIR)/ft_strtonum.c \
				  $(SRCDIR)/ft_strtonum_u.c \
				  $(SRCDIR)/ft_strtoupper.c \
				  $(SRCDIR)/ft_strtrim.c \
				  $(SRCDIR)/ft_substr.c \
				  $(SRCDIR)/ft_tolower.c \
				  $(SRCDIR)/ft_toupper.c
OBJECTS     	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$\
				  $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
INCLUDENAME		= $(subst lib,,$(NAME))

##

all:
	make -j4 $(BINDIR)/$(NAME).a

$(NAME): $(BINDIR)/$(NAME).a

##

static: $(BINDIR)/$(NAME).a

$(BINDIR)/$(NAME).a: $(BUILDDIR)/ $(BINDIR)/ $(OBJECTS)
	ar -cr $(BINDIR)/$(NAME).a $(BUILDDIR)/*.$(OBJEXT)

##

so: $(BINDIR)/$(NAME).so

$(BINDIR)/$(NAME).so: $(BUILDDIR)/ $(BINDIR)/ $(OBJECTS)
	$(CC) -shared $(BUILDDIR)/*.$(OBJEXT) -o $(BINDIR)/$(NAME).so

##

$(TESTNAME): $(BINDIR)/$(NAME).a $(UNITTEST)
	$(CC) $(CFLAGS) $(UNITTEST) -I$(HEADERDIR)/ -L$(BINDIR)/ \
	-l$(INCLUDENAME) -o $(TESTNAME)

##

clean:
	/bin/rm -rf $(BUILDDIR)/

fclean:
	$(MAKE) clean
	/bin/rm -f $(TESTNAME)
	/bin/rm -rf $(BINDIR)/

re:
	$(MAKE) fclean
	$(MAKE) all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BINDIR)/:
	mkdir -p $(BINDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT) $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADERDIR)/ -c $< -o $@

.PHONY: all so static clean fclean re

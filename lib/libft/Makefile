# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: joppe <joppe@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/23 17:53:14 by jkoers        #+#    #+#                  #
#    Updated: 2020/12/03 21:44:24 by jkoers        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME      		= libft

CC          	= gcc
CFLAGS      	= -Wall -Wextra -Werror

SRCEXT      	= c
SRCDIR      	= src
HEADERDIR		= include
OBJEXT      	= o
BUILDDIR    	= obj
BINDIR			= bin
HEADER			= include/libft.h

TESTNAME		= testor
UNITTEST		= test/test_ft_numtostr_pad.c

SOURCES     	= $(shell find '$(SRCDIR)/' -type f -name '*.$(SRCEXT)')
OBJECTS     	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$\
				  $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
INCLUDENAME		= $(subst lib,,$(NAME))

##

all: $(BINDIR)/$(NAME).a

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

fclean: clean
	/bin/rm -f $(TESTNAME)
	/bin/rm -rf $(BINDIR)/

re: fclean all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BINDIR)/:
	mkdir -p $(BINDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT) $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADERDIR)/ -c $< -o $@

.PHONY: all help so static clean fclean re

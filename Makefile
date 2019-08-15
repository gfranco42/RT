# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 12:13:05 by gfranco           #+#    #+#              #
#    Updated: 2019/08/12 17:46:59 by gfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors.

ORANGE =	\033[1;33m   #It is actually Yellow, but i changed yellow to orange.

GREEN =		\033[1;32m

RED =		\033[1;31m

RES =		\033[0m

#------------------------------------------------------------------------------#

NAME = 		rt

SRCDIR =	./srcs

INCDIR =	./includes

OBJDIR =	./objs

SRC =		calcul_base.c camera_check.c cone_check.c cylinder_check.c         \
			draw_prim.c event.c extract_data.c initialize.c init_prim.c        \
			lexer.c light_check.c main.c objects_check.c parser.c              \
			plane_check.c sphere_check.c light_calculation.c                   \
			reflection.c shadow.c vec_calculation.c vec_calculation2.c         \
			calcul_normal.c intersections.c light_intersections.c main_algo.c  \
			extract_data2.c intersect_algo.c check_tools.c color_calculation.c \
			refraction.c utils.c intersect_algo2.c luminance_alteration.c      \
			extract_data3.c color_calculation2.c amb_diff_spec_calculation.c

INC =		rt.h

SRCS =		$(SRC:%=$(SRCDIR)/%)

OBJS =		$(SRC:%.c=$(OBJDIR)/%.o)

INCS =		$(INC:%=$(INCDIR)/%)

LIBDIR =	./libft

LIBNAME =	libft.a

LIB =		$(LIBDIR)/$(LIBNAME)

LIBINC =	$(LIBDIR)

#------------------------------------------------------------------------------#

CC =		clang

CFLAGS =	-Wall			\
			-Wextra			\
			-Werror			\
			-g				\

INCFLAGS =	-I $(INCDIR)			\
			-I $(LIBINC)			\
			-I /usr/local/include

LFLAGS =	-L $(LIBDIR) -l$(LIBNAME:lib%.a=%)	\
			-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit	\
			-lpthread

FLAGS =		$(CFLAGS)		\
			$(INCFLAGS)

#------------------------------------------------------------------------------#
# Primary rules

all:
	$(MAKE) -C $(LIBDIR)
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

$(OBJS): $(INCS) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@$(MAKE) -C $(LIBDIR) fclean
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBDIR) fclean
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all

.PHONY: all clean re fclean

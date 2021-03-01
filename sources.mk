# SRC = $(shell find $(SRCDIR) -name "*.$(SRCEXT)" -exec basename {} \;)

SRC	=	src/constants.c \
		src/exit.c \
		src/gui/gui.c \
		src/gui/gui2.c \
		src/gui/gui_init.c \
		src/gui/save_bmp.c \
		src/main.c \
		src/parse_rt/clamp.c \
		src/parse_rt/count_rules.c \
		src/parse_rt/parse_rule_non_shape.c \
		src/parse_rt/parse_rule_shapes.c \
		src/parse_rt/parse_rule_square.c \
		src/parse_rt/rt_file.c \
		src/parse_rt/rt_file_set.c \
		src/ray/color.c \
		src/ray/compute_color.c \
		src/ray/intersect/intersect.c \
		src/ray/intersect/intersect_cylinder.c \
		src/ray/intersect/intersect_plane.c \
		src/ray/intersect/intersect_sphere.c \
		src/ray/intersect/intersect_triangle.c \
		src/ray/normalize.c \
		src/ray/quadratic.c \
		src/ray/ray_from_pix.c \
		src/ray/ray_to_color.c \
		src/ray/render.c \
		src/ray/vector.c \
		src/ray/vector2.c

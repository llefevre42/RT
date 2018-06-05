# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thvocans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 19:03:58 by thvocans          #+#    #+#              #
#    Updated: 2018/06/05 22:57:31 by llefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re libmlx.a libclean libfclean mlxclean libft.a libvec.a relib

NAME = rt

MAC_VER := $(shell uname -r | sed 's/\..*//')
ifeq ($(MAC_VER), 15)
GLIB_FOLD := ./mlx_el_capitan
else
GLIB_FOLD := ./mlx_sierra
endif

CC = @gcc $(FLAGS)
FLAGS =  -O2 -Wall -Wextra -Werror -I $(H_FOLD) -I $(GLIB_FOLD)

C_FOLD = ./src
O_FOLD = ./obj/
H_FOLD = ./includes
LIB_FOLD = ./libft

RT_H = $(H_FOLD)/rt.h
LIB = $(LIB_FOLD)/libft.a
GLIB = $(GLIB_FOLD)/libmlx.a

SRC = src/main\
		src/draw\
		src/draw2\
		src/intervalle\
		src/intervalle2\
		src/intervalle3\
		src/perlin\
		src/perlin2\
		src/add_object\
		src/error\
		src/find_color\
		src/find_color2\
		src/hook\
		src/hook2\
		src/init\
		src/intersect_shape\
		src/intersection\
		src/intersection2\
		src/intersection3\
		src/light\
		src/parsing\
		src/parsing2\
		src/parsing3\
		src/parsing_transf\
		src/quadric\
		src/raytracer\
		src/rotate\
		src/rotate2\
		src/rotate_obj\
		src/shape\
		src/gene_interface\
		src/put_cub\
		src/put_mousse\
		src/put_mousse2\
		src/menu_form\
		src/menu_form2\
		src/put_keycode\
		src/menu_light\
		src/menu_light2\
		src/event_mousse_form\
		src/event_mousse_form2\
		src/event_mousse_light\
		src/event_mousse_light2\
		src/custom_put\
		src/menu_add_22\
		src/menu_add_22_2\
		src/menu_modif_21\
		src/menu_modif_21_2\
		src/menu_file\
		src/menu_file_10\
		src/menu_light_41\
		src/menu_light_42\
		src/menu_cam\
		src/menu_modif_30\
		src/texture\
		src/texture2\
		src/texture3\
		src/parse_text\
		src/menu_split\
		src/screen\
		src/block\
		src/reset\
		src/what_item\
		src/ls_du_pauvre\
        src/check\
        src/filters\
        src/preview_init\
        src/preview_init2\
        src/split_in src/init_text src/textures\
		src/parsing_choice\
		src/gnb\
		src/pars_json\
		src/ft_error_txt\
		src/jsonator\
		src/atof_custom\
	   	src/ft_cam\
	   	src/ft_obj_list\
	   	src/ft_brackets\
		src/ft_light\
	   	src/generic_params\
	   	src/lum_limit\
	   	src/misc_params\
		src/ft_quad\
	   	src/ft_obj\
	   	src/param_ator\
		src/store_list\

O_FILE = $(addsuffix .o,$(addprefix $(O_FOLD),$(notdir $(SRC))))

all: $(NAME)

$(NAME): $(GLIB) $(LIB) $(O_FOLD) $(O_FILE)
	@gcc $(FLAGS) $(LIB) $(GLIB) -framework OpenGL -framework Appkit -o $@ $(O_FILE)
	@echo "\r\033[32mexecutable OK !        \033[0m"

$(O_FOLD)%.o: src/%.c $(RT_H)
	@gcc -c $< $(FLAGS) -I$(LIB_FOLD) -o $@
	@printf "\r\033[32m$@\033[0m                                               "
#@echo "\033[32m$@\033[0m"

$(O_FOLD)%.o: src_ludo/%.c $(RT_H)
	@gcc -c $< $(FLAGS) -I$(LIB_FOLD) -o $@
	@printf "\r\033[32m$@\033[0m                                               "

$(O_FOLD)%.o: interface_rt/%.c $(RT_H)
	@gcc -c $< $(FLAGS) -I$(LIB_FOLD) -o $@
	@printf "\r\033[32m$@\033[0m                                               "

$(O_FOLD)%.o: json/%.c $(RT_H) $(H_FOLD)/*.h
	@gcc -c $< $(FLAGS) -I$(LIB_FOLD) -o $@
	@printf "\r\033[32m$@\033[0m                                               "

$(O_FOLD):
	@mkdir $(O_FOLD)

.PHONY: libft.a libmlx.a 

libft.a: $(LIB)

libmlx.a: $(GLIB)

$(LIB):
	@$(MAKE) -C $(LIB_FOLD)

.PHONY: libclean libfclean

libclean:
	@$(MAKE) -C $(LIB_FOLD) clean

libfclean:
	@$(MAKE) -C $(LIB_FOLD) fclean

$(GLIB):
	@$(MAKE) -C $(GLIB_FOLD)

.PHONY: mlxclean mlxfclean

mlxclean:
	@$(MAKE) -C $(GLIB_FOLD) clean

mlxfclean:
	@$(MAKE) -C $(GLIB_FOLD) fclean

.PHONY: clean cc fclean

clean: libclean mlxclean
	@/bin/rm -f $(O_FILE)
	@echo "\033[36mrm obj files\033[0m"
	@/bin/rm -rf $(O_FOLD)
	@echo "\033[36mrm obj folder\033[0m"

cc: clean
	@/bin/rm -f $(NAME)

fclean: clean libfclean mlxfclean
	@/bin/rm -f $(NAME)
	@echo "\033[32mrm $(NAME)\033[0m"

.PHONY: relib remlx re mk

relib: libfclean libft.a

remlx: mlxfclean libmlx.a

re: fclean all

mk: cc all

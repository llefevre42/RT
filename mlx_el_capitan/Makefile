#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c\
	 mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	@rm -f $(OBJ) *~
	@echo "\033[36mrm mlx .o files\033[0m"

fclean: clean
	@rm -f $(NOM)
	@echo "\033[36mrm libmlx.a\033[0m"
re: clean all

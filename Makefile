.PHONY: all clean bonus fclean re

NAME = cub3D

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)libft.a

LIBMLX_DIR = ./mlx

LIBMLX = $(LIBMLX_DIR)libmlx.dylib

MAKE = make

CLEAN = clean

FCLEAN = fclean

SRC = main.c\
	utils/parsing.c\
	utils/map_pars.c\
	utils/error.c\
	utils/check_args.c\
	utils/close_window.c\
	utils/my_mlx_pixel_put.c\
	utils/screen.c\
	utils/my_rgb.c\
	utils/map.c\
	utils/pars_check.c\
	utils/pars_check2.c\
	utils/start.c\
	utils/sprites.c\
	utils/plr_dir.c\
	utils/sprite.c\
	utils/side.c\
	utils/side2.c\
	utils/cub_util.c\
	utils/cub_utils.c\
	
OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra -g -O0

FLAGMLX = -framework OpenGL -framework AppKit

OPTION = -c -D GL_SILENCE_DEPRECATION

OPTIONOBJ = -o

DEL = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	@cd $(LIBFT_DIR) && mv ./libft.a ../
	@cd $(LIBMLX_DIR) && mv ./libmlx.dylib ../
	@$(CC) $(FLAG) $(OBJ) -L. -lmlx -lft $(FLAGSMLX) $(OPTIONOBJ) $(NAME)

$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE)

$(LIBMLX):
	@cd $(LIBMLX_DIR) && $(MAKE)

%.o: %.c
	@$(CC) $(FLAG) $(OPTION) $< $(OPTIONOBJ) $@

clean:
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(CLEAN)
	@cd $(LIBMLX_DIR) && $(MAKE) $(CLEAN)
	
fclean: clean
	@$(DEL) $(NAME) ./libft.a ./libmlx.dylib
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(FCLEAN)
	
re: fclean all

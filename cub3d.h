#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include "mlx/mlx.h"
#include <fcntl.h>
#include "libft/libft.h"

# define TEXHEIGTH 64
# define TEXWIDTH 64

typedef struct      s_parser
{
    int             res_w;
    int             res_l;

    char            *n_texture;
    char            *s_texture;
    char            *w_texture;
    char            *e_texture;

    char            *spr_tex;

    int             f_r;
    int             f_g;
    int             f_b;
    int             f_flag;

    int             c_r;
    int             c_g;
    int             c_b;
    int             c_flag;

    char            **map;

    char            *player;
    int             player_x;
    int             player_y;

    int             size_map;

    int             col_sprite;
}                   t_parser;

typedef struct      s_plr
{
    double          x;
    double          y;
    double          dir;
    char            dir_symbol;
    double          dirX;
    double          dirY;
    double          planeX;
    double          planeY;
    double          start;
    double          end;
}                   t_plr;

typedef struct      s_data
{
    void            *img;
    char            *addr;
    int             bits_per_pixel;
    int             line_length;
    int             endian;
}                   t_data;

typedef struct      s_point_print
{
    double          x;
    double          y;
}                   t_point_print;

typedef struct      s_norm_print_sprite
{
    double          sprite_x;
    double          sprite_y;
    double          inv_det;
    double          transform_x;
    double          transform_y;
    int             sprite_screen_x;
    int             sprite_height;
    int             draw_start_y;
    int             draw_end_y;
    int             sprite_width;
    int             draw_start_x;
    int             draw_end_x;
    int             tex_x;
    int             d;
    int             tex_y;
    int             color;
}                   t_norm_print_sprite;

typedef struct      s_norm_print_map
{
    double          camera_x;
    double          ray_dir_x;
    double          ray_dir_y;
    int             map_x;
    int             map_y;
    double          side_dist_x;
    double          side_dist_y;
    double          delta_dist_x;
    double          delta_dist_y;
    double          perp_wall_dist;
    int             step_x;
    int             step_y;
    int             hit;
    int             side;
    int             line_height;
    int             draw_start;
    int             draw_end;
    double          wall_x;
    int             tex_x;
    double          step;
    double          tex_pos;
    int             tex_y;
}                   t_norm_print_map;

typedef struct s_cub
{
    void            *mlx;
    void            *mlx_wind;
    t_parser        p;
    t_data          t_n;
    t_data          t_s;
    t_data          t_w;
    t_data          t_e;
    t_data          t_spr;
    t_data          data;
    t_point_print   point;
    t_plr           plr;
    float           *x;
    float           *y;
    float           *dist;
    double          *close_sprite;
}                   t_cub;

int             main(int argc, char **argv);
int             my_rgb(int r, int g, int b);
int             close_win(t_cub *cub);
void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
void            free_map(t_list **lst);
void            check_all(t_cub *cub);
void            space_in_rgb(char *line, t_cub *cub);
void            check_ceiling(t_cub *cub);
void            check_floor(t_cub *cub);
void            resolution(t_cub *cub);
void            space_tab(char *line, t_cub *cub);
void            arguments(int argc, char **argv, t_cub *cub);
int             save(char *argv);
int             map_name(char *argv);
void            get_floor(char *tmp, t_cub *cub);
void            get_ceilling(char *tmp, t_cub *cub);
void            space_in_map(char *str, t_cub *cub);
void            start(t_cub *cub, int argc);
void            check_symbols(int size, t_cub *cub);
unsigned int    get_pixel(t_data *data, int x, int y);
void            error(char *str, t_cub *cub);
void            parsing(char **argv, t_cub *cub);
void            map_parsing(int fd, t_cub *cub);
void            screen(t_cub *cub);
void            player_dir(t_cub *cub);
void            get_sprite(t_cub *cub);
void            turn_right(t_cub *cub, double r);
void            move_right(t_cub *cub, double s);
void            move_left(t_cub *cub, double s);
void            move_back(t_cub *cub, double s);
void            move_forward(t_cub *cub, double s);
void            turn_left(t_cub *cub, double r);
void            coordinat_direction(t_norm_print_map *n, int *x, t_cub *cub);
void            ray_direction(t_norm_print_map *n, t_cub *cub);
void            ray_wall_stop(t_norm_print_map *n, t_cub *cub);
void            distance(t_norm_print_map *n, t_cub *cub, int *x);
void            fill_colors(t_norm_print_map *n, t_cub *cub, int *x, int *y);
void            attach_textures(t_norm_print_map *n, t_cub *cub, int *x, int *y);
void            set_sprite(t_cub *cub, t_norm_print_sprite *s, int *i);
void            sprite_norm(t_cub *cub, t_norm_print_sprite *s,
                                        int *y, int *stripe);
int             count(t_cub *cub);
void            where_is_sprite(t_cub *cub);
void            sort(t_cub *cub);

#endif

/*
** my.h for my.h in /home/pion_b/graph/include
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sun Nov 13 21:40:31 2016 Virgile
** Last update Sat Jan 14 21:41:49 2017 Virgile
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <math.h>

/*
** MACROS
*/
#define WTH (1280)
#define HGT (720)

typedef struct		s_my_framebuffer
{
  sfUint8*		pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_ray
{
  sfVector2f		sidedist;
  sfVector2f		map;
  sfVector2f		deltadist;
  sfVector2f		raydir;
  sfVector2i		step;
  sfVector2f		pos;
  sfVector2f		dir;
  int			hit;
  int			token;
  float			angle;
  int			side;
  float			norm;
  sfVector2f	       	angel;
  sfVector2f		x_angel;
}			t_ray;

typedef struct		s_token
{
  int			up;
  int			down;
  int			left;
  int			right;
}			t_token;

typedef struct		s_data
{
  int			**map;
  char			*path_pic;
  char			*path;
  t_ray			*r;
  t_my_framebuffer	*buffer;
  t_my_framebuffer	*video[584];
  t_my_framebuffer	*wall;
  t_my_framebuffer	*sky;
  t_my_framebuffer	*rateau;
  t_my_framebuffer	*rateau2;
  t_my_framebuffer	*ange;
  t_my_framebuffer	*opendoor;
  t_my_framebuffer	*closedoor;
  t_my_framebuffer	*titre;
  t_my_framebuffer	*tardis;
  t_my_framebuffer	*loose;
  t_my_framebuffer	*win;
  sfThread		*thread;
  sfThread		*thread2;
  sfThread		*thread3;
  sfThread		*thread4;
  sfThread		*thread_cast;
  sfThread		*thread_cast2;
  sfSprite		*sprite;
  sfTexture		*texture;
  sfClock		*clock;
  sfMusic		*music;
  sfMusic		*open;
  sfMusic		*close;
  sfMusic		*intro;
  sfMusic		*win_music;
  sfMusic		*loose_music;
  sfEvent		event;
  sfColor		color;
  sfColor		color_wall;
  sfColor		background;
  sfVector2f   		pos_player;
  sfVector2f		screen;
  sfVector2f		ray;
  sfVector2i		mouse;
  sfVector2i		mapSize;
  float			real;
  float			real_angel;
  float			angle;
  float			y;
  float			norm;
  float			new_angle;
  float			ms;
  float			fps;
  int			x;
  int			spe_bloc;
  int			bloc;
  int			porte;
  int			start;
  int			movie;
  int			clic;
  int			fov;
  int			sky_pas;
  int			i;
  int			touch;
  int			maprint;
}			t_data;

/*
** Main functions
*/

void			my_thread_cast(void *d);
void			my_thread_cast2(void *d);
void			my_win(t_data *d);
void			my_loose(t_data *d);
void			my_game(t_data *d);
char			*get_path(char *path, int i);
void			thread_go(t_data *d, sfThread *thread);
sfColor			get_color(t_my_framebuffer *buffer, int i, int h, float wall);
void			my_menu(t_data *d);
void			my_draw_wall(t_data *d, sfVector2i from, sfVector2i to, float wall);
void			make_walls(t_data *d, float x);
sfColor			get_color(t_my_framebuffer *buffer, int i, int h, float wall);
void			my_load_music(t_data *d);
void			my_load_video(t_data *d);
void			my_load_pictures(t_data *d);
void			wall(t_data *w);
float			raycast(sfVector2f pos, float direction, int **map, sfVector2i mapSize);
void			full_buffer(t_my_framebuffer *framebuffer, sfColor color);
void			buffer_destroy(t_my_framebuffer *buffer);

sfColor			edit_color(int a, int r, int g, int b);
int			main(int ac, char **av);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
int			**get_map(char *path, t_data *d);
int			my_strlen(char *str);

/*
** Print functions  : affichage sur un framebuffer des différents objets du jeu
*/
sfColor			color_pos(int x, int y, t_my_framebuffer *buffer);
void			print_rateau(t_data *d);
void			print_sky(t_data *d);
void			print_map(t_data *d);
void			print_video(t_my_framebuffer *buffer, t_my_framebuffer *pic);
void			print_titre(t_my_framebuffer *buffer, t_my_framebuffer *titre);
void			print_loose(t_my_framebuffer *buffer, t_my_framebuffer *loose);

/*
** bitmap functions : Chargement des bitmaps en multithread pour la video
** d'intro
*/
void			thread_bitmap(void *data);
void			thread_bitmap2(void *data);
void			thread_bitmap3(void *data);
void			thread_bitmap4(void *data);

/*
** Raycast : raycasting sur un int **map pour calculer la distance aux murs
*/
void			ini_step(t_ray *r);
void			ini_ray(t_ray *r, float angle, sfVector2f pos);
void			my_thread_cast(void *data);
t_ray			*rcast(sfVector2f pos, float direction,	\
			       t_data *d, sfVector2i mapSize);
void			my_cast(t_data *d);
void			r_x(t_ray *r);
void			r_y(t_ray *r);

/*
** Mainloop : boucle principale du programme
*/
void			init_loop(t_data *d);
void			my_refresh(t_data *d, sfRenderWindow *window);
void			clean_objects(sfRenderWindow *window, t_data *d);
int			mainloop(sfRenderWindow *window, t_data *d);

/*
** Events : gestion des touches et de la souris
*/
void			events(t_data *d, sfRenderWindow *window);

/*
** Geometric functions
*/
sfVector2f		move_forward(sfVector2f pos, float direction, float distance);
void			my_pixel(t_my_framebuffer *framebuffer,	\
				 int x, int y, sfColor color);
void			my_put_pixel(t_my_framebuffer *framebuffer,	\
				     int x, int y, sfColor color);
void			my_draw_line(t_my_framebuffer *framebuffer,	\
				     sfVector2i from, sfVector2i to,	\
				     sfColor color);
void			my_line(t_my_framebuffer *framebuffer,	\
				     sfVector2i from, sfVector2i to,	\
				     sfColor color);
float			get_coef(int a, int b, int c, int d);
sfVector2i		makepoint(int x, int y);

#endif /*MY_H_*/

/*
** mainloop.c for mainloop in /home/pion_b/courbe
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Fri Dec  2 21:28:36 2016 Virgile
** Last update Sat Jan 14 21:25:38 2017 Virgile
*/

#include "my.h"
#include "stdio.h"
#include "bitmap.h"

void			paint_buffer(t_my_framebuffer *buffer,\
				     t_my_framebuffer *web)
{
  int			i;
  sfColor		color;

  i = 0;
  while (i < web->width * web->height * 4)
    {
      color.r = web->pixels[i];
      color.g = web->pixels[i + 1];
      color.a = web->pixels[i + 2];
      color.b = web->pixels[i + 3];
      my_put_pixel(buffer, (i / 4) % web->width, (i / 4) / web->width, color);
      i+= 4;
    }
}

void			init_loop(t_data *d)
{
  d->buffer = my_framebuffer_create(WTH, HGT);
  d->color = sfWhite;
  d->background = sfBlack;
  d->sprite = sfSprite_create();
  d->texture = sfTexture_create(WTH, HGT);
  d->pos_player.x = 2;
  d->pos_player.y = 2;
  d->angle = 60;
  d->fov = 55;
  d->ms = 0.1;
  d->sky_pas = 0;
  d->maprint = 0;
  d->porte = 0;
  d->start = 0;
  d->movie = 0;
  my_load_video(d);
  my_load_pictures(d);
  my_load_music(d);
  sfMusic_play(d->intro);
  d->clock = sfClock_create();
  d->thread_cast = sfThread_create(&my_thread_cast, (void *)d);
}

void			my_refresh(t_data *d, sfRenderWindow *window)
{
  full_buffer(d->buffer, d->background);
  if (d->start == 0)
    my_menu(d);
  if (d->start == 1)
    {
      sfMusic_play(d->music);
      sfMusic_stop(d->intro);
      d->start = 2;
    }
  if (d->start == 2)
    my_game(d);
  if (d->start == 3)
    my_loose(d);
  if (d->start == 4)
    my_win(d);
  sfTexture_updateFromPixels(d->texture, d->buffer->pixels, WTH, HGT, 0, 0);
  sfSprite_setTexture(d->sprite, d->texture, sfTrue);
  sfRenderWindow_drawSprite(window, d->sprite, NULL);
  sfRenderWindow_display(window);
  sfRenderWindow_clear(window, sfBlack);
}

void			clean_objects(sfRenderWindow *window, t_data *d)
{
  (void)window;
  sfSprite_destroy(d->sprite);
  d->sprite = sfSprite_create();
  sfTexture_destroy(d->texture);
  d->texture = sfTexture_create(WTH, HGT);
  buffer_destroy(d->buffer);
  d->buffer = my_framebuffer_create(WTH, HGT);
}

int			mainloop(sfRenderWindow *window, t_data *d)
{
  sfVector2i		pos;

  pos.y = HGT / 2;
  pos.x = WTH / 2;
  init_loop(d);
  sfRenderWindow_setMouseCursorVisible(window, 0);
  my_refresh(d, window);
  while  (sfRenderWindow_isOpen(window))
    {
      d->fps = sfTime_asSeconds(sfClock_getElapsedTime(d->clock));
      d->mouse = sfMouse_getPositionRenderWindow(window);
      sfMouse_setPositionRenderWindow(pos, (const sfRenderWindow *)window);
      events(d, window);
      clean_objects(window, d);
      my_refresh(d, window);
      d->fps++;
    }
  return (0);
}

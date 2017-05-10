/*
** load_files.c for load_files in /home/pion_b/wolf3d/bonus
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sat Jan 14 20:45:18 2017 Virgile
** Last update Sun Jan 15 05:59:08 2017 Virgile
*/

#include "my.h"
#include "bitmap.h"

void		my_load_music(t_data *d)
{
  d->music = sfMusic_createFromFile("./src/music/musicdoctor.ogg");
  d->open = sfMusic_createFromFile("./src/music/fx_close.ogg");
  d->close = sfMusic_createFromFile("./src/music/fx_open.ogg");
  d->intro = sfMusic_createFromFile("./src/music/intro.ogg");
  d->loose_music = sfMusic_createFromFile("./src/music/loose.ogg");
  d->win_music = sfMusic_createFromFile("./src/music/win_music.ogg");
}

void		my_load_pictures(t_data *d)
{
  t_bitmap	*wall;

  wall = open_bitmap("./src/bmp/cobble.bmp");
  d->wall = wall->buffer;
  wall = open_bitmap("./src/bmp/sky_720.bmp");
  d->sky = wall->buffer;
  wall = open_bitmap("./src/bmp/rateau.bmp");
  d->rateau = wall->buffer;
  wall = open_bitmap("./src/bmp/rateau2.bmp");
  d->rateau2 = wall->buffer;
  wall = open_bitmap("./src/bmp/angels.bmp");
  d->ange = wall->buffer;
  wall = open_bitmap("./src/bmp/opendoor.bmp");
  d->opendoor = wall->buffer;
  wall = open_bitmap("./src/bmp/tardis.bmp");
  d->tardis = wall->buffer;
  wall = open_bitmap("./src/bmp/closedoor.bmp");
  d->closedoor = wall->buffer;
  wall = open_bitmap("./src/bmp/titre.bmp");
  d->titre = wall->buffer;
  wall = open_bitmap("./src/bmp/loose.bmp");
  d->loose = wall->buffer;
  wall = open_bitmap("./src/bmp/win.bmp");
  d->win = wall->buffer;
}

void		my_load_video(t_data *d)
{
  d->path_pic = "./src/video/video_000";
  d->i = 0;
  d->thread = sfThread_create(&thread_bitmap, (void *)d);
  d->thread2 = sfThread_create(&thread_bitmap2, (void *)d);
  d->thread3 = sfThread_create(&thread_bitmap3, (void *)d);
  d->thread4 = sfThread_create(&thread_bitmap4, (void *)d);
  sfThread_launch(d->thread);
  sfThread_launch(d->thread2);
  sfThread_launch(d->thread3);
  sfThread_launch(d->thread4);
  sfThread_wait(d->thread);
  sfThread_wait(d->thread2);
  sfThread_wait(d->thread3);
  sfThread_wait(d->thread4);
  sfThread_destroy(d->thread);
  sfThread_destroy(d->thread2);
  sfThread_destroy(d->thread3);
  sfThread_destroy(d->thread4);

}

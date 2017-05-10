/*
** my_menu.c for my_menu in /home/pion_b/wolf3d/bonus
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Jan  9 14:12:09 2017 Virgile
** Last update Sat Jan 14 21:15:55 2017 Virgile
*/

#include "my.h"

void		my_game(t_data *d)
{
  print_sky(d);
  my_cast(d);
  print_rateau(d);
  if (d->maprint == 1)
    print_map(d);
}

void		my_win(t_data *d)
{
   if (d->pos_player.x != 2)
    {
    sfMusic_play(d->win_music);
    sfMusic_stop(d->music);
    }
  d->pos_player.x = 2;
  d->pos_player.y = 2;
  print_loose(d->buffer, d->win);
}

void		my_loose(t_data *d)
{
  if (d->pos_player.x != 2)
    {
    sfMusic_play(d->loose_music);
    sfMusic_stop(d->music);
    }
  d->pos_player.x = 2;
  d->pos_player.y = 2;
  print_loose(d->buffer, d->loose);
}

void		my_menu(t_data *d)
{
  if (d->movie < 584)
    {
      if (d->video[d->movie] != NULL)
	print_video(d->buffer, d->video[d->movie]);
    }
  else
    d->start = 1;
  print_titre(d->buffer, d->titre);
  d->movie = (int)(d->fps * 25);
}

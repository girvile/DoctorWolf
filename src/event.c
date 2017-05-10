/*
** event.c for event in /home/pion_b/courbe
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Fri Dec  2 21:34:15 2016 Virgile
** Last update Mon Jan 16 18:30:26 2017 Virgile
*/

#include "my.h"

void			move(t_data *d, float move, int angle)
{
  sfVector2f		new_pos;
  sfVector2f		safe_pos;

  if (move > 0)
    new_pos = move_forward(d->pos_player, d->angle + angle, move + 0.3);
  else
    new_pos = move_forward(d->pos_player, d->angle + angle, move - 0.3);
  if (d->map[(int)new_pos.y][(int)new_pos.x] == 0 ||	\
      d->map[(int)new_pos.y][(int)new_pos.x] == 4 ||	\
      d->map[(int)new_pos.y][(int)new_pos.x] == 6)
    {
      safe_pos = move_forward(d->pos_player, d->angle + angle, move);
      d->pos_player.x = safe_pos.x;
      d->pos_player.y = safe_pos.y;
    }
}

void			touch_move(t_data *d)
{
  if (sfKeyboard_isKeyPressed(sfKeyUp)||	\
      sfKeyboard_isKeyPressed(sfKeyZ))
    move(d, d->ms, 0);
  if (sfKeyboard_isKeyPressed(sfKeyDown)||	\
      sfKeyboard_isKeyPressed(sfKeyS))
    move(d, -d->ms, 0);
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    move(d, d->ms / 2, -90);
  if (sfKeyboard_isKeyPressed(sfKeyD))
    move(d, d->ms / 2, 90);
  if (sfKeyboard_isKeyPressed(sfKeyRight)||	\
      sfKeyboard_isKeyPressed(sfKeyE))
    {
      d->angle += 5;
      d->sky_pas += 10;
    }
  if (sfKeyboard_isKeyPressed(sfKeyLeft)||	\
      sfKeyboard_isKeyPressed(sfKeyA))
    {
      d->angle -= 5;
      d->sky_pas -= 10;
    }
}

void			mouse_move(t_data *d, sfRenderWindow *window)
{
  sfVector2i		new_mouse;

  new_mouse = sfMouse_getPositionRenderWindow(window);
  if (new_mouse.x < d->mouse.x)
    {
      d->angle += (d->mouse.x - new_mouse.x) / 2;
      d->sky_pas += (d->mouse.x - new_mouse.x) * 2;
    }
  if (new_mouse.x > d->mouse.x)
    {
      d->angle -= (new_mouse.x - d->mouse.x) / 2;
      d->sky_pas -= (new_mouse.x - d->mouse.x) * 2;
    }
}

void			events(t_data *d, sfRenderWindow *window)
{
  touch_move(d);
  mouse_move(d, window);
  if (d->map[(int)d->pos_player.y][(int)d->pos_player.x] == 6)
    d->start = 4;
  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(window);
  if (sfKeyboard_isKeyPressed(sfKeySpace))
    d->start = 1;
  (sfKeyboard_isKeyPressed(sfKeyLShift)) ? (d->maprint = 1) : (d->maprint = 0);

  if (sfRenderWindow_pollEvent(window, &d->event))
    {
      if (d->event.type == sfEvtClosed)
	sfRenderWindow_close(window);
    }
  if (sfMouse_isButtonPressed(sfMouseLeft))
    d->clic = 1;
  else
    {
    d->clic = 0;
    d->porte = 0;
    }
}

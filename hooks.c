/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:23:31 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/21 15:41:57 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int key_pressed(int keycode, void *param)
{
    t_game *g = (t_game *)param;

    if (keycode == XK_Up || keycode ==  XK_w) // W
        move_player(g, 0, -1);
    else if (keycode == XK_Down|| keycode == XK_s) // S
        move_player(g, 0, 1);
    else if (keycode == XK_Left || keycode == XK_a) // A
        move_player(g, -1, 0);
    else if (keycode == XK_Right || keycode == XK_d) // D
        move_player(g, 1, 0);
    else if (keycode == XK_Escape) // ESC
        exit(0);
    return (0);
}

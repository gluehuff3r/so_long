/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:19:11 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/06 15:52:10 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"


int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 400, 400, "test");

    (void)win;   // <-- fixes the unused variable error
    mlx_hook(win, 17, 0, close_window, 0);
    mlx_hook(win, 2, 1L<<0, key_pressed, 0);
    mlx_loop(mlx);
}

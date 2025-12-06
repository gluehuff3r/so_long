/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:23:31 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/06 15:53:56 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
	(void)param;
	exit(0);
	return(0);
}
int key_pressed(int keycode, void *param)
{
	(void)param;
	printf("key pressed : %d", keycode);
	return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:56:58 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 12:55:34 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player(t_player *player)
{
	player->up = (char **)malloc(sizeof(char *) * 4);
	player->up[0] = "src/textures/up1.xpm";
	player->up[1] = "src/textures/up2.xpm";
	player->up[2] = "src/textures/up3.xpm";
	player->up[3] = "\0";
	player->down = (char **)malloc(sizeof(char *) * 4);
	player->down[0] = "src/textures/down1.xpm";
	player->down[1] = "src/textures/down2.xpm";
	player->down[2] = "src/textures/down3.xpm";
	player->down[3] = "\0";
	player->left = (char **)malloc(sizeof(char *) * 4);
	player->left[0] = "src/textures/left1.xpm";
	player->left[1] = "src/textures/left2.xpm";
	player->left[2] = "src/textures/left3.xpm";
	player->left[3] = "\0";
	player->right = (char **)malloc(sizeof(char *) * 4);
	player->right[0] = "src/textures/right1.xpm";
	player->right[1] = "src/textures/right2.xpm";
	player->right[2] = "src/textures/right3.xpm";
	player->right[3] = "\0";
}

void	ft_enemy_init(t_enemy *enemy)
{
	enemy->file = (char **)malloc(sizeof(char *) * 5);
	enemy->file[0] = "src/textures/enemy1.xpm";
	enemy->file[1] = "src/textures/enemy2.xpm";
	enemy->file[2] = "src/textures/enemy3.xpm";
	enemy->file[3] = "src/textures/enemy2.xpm";
	enemy->file[4] = "\0";
}

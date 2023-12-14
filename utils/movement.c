/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:07:21 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/14 19:13:56 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//enleve les element recupere
void	change_indice(char *c, char *v)
{
	*c = '0';
	*v = 'P';
}

//modifie la position du joueur selon la case d'a cote
void	key_hook2(int keycode, t_data *data)
{
	if (keycode == 0)
		if ((data->map[data->pos_i][data->pos_j - 1] == '0'
			|| data->map[data->pos_i][data->pos_j - 1] == 'C'
			|| data->map[data->pos_i][data->pos_j - 1] == 'E'
			|| data->map[data->pos_i][data->pos_j - 1] == 'N'))
			test_left(data);
	if (keycode == 13)
		if ((data->map[data->pos_i - 1][data->pos_j] == '0'
			|| data->map[data->pos_i - 1][data->pos_j] == 'C'
			|| data->map[data->pos_i - 1][data->pos_j] == 'E'
			|| data->map[data->pos_i - 1][data->pos_j] == 'N'))
			test_up(data);
}

int	key_hook(int keycode, t_data *data)
{
	int	nb;

	nb = 0;
	if (keycode == 53)
		exit_1(data, keycode);
	if (keycode == 2)
		if ((data->map[data->pos_i][data->pos_j + 1] == '0'
			|| data->map[data->pos_i][data->pos_j + 1] == 'C'
			|| data->map[data->pos_i][data->pos_j + 1] == 'E'
			|| data->map[data->pos_i][data->pos_j + 1] == 'N'))
			test_right(data);
	if (keycode == 1)
		if ((data->map[data->pos_i + 1][data->pos_j] == '0'
			|| data->map[data->pos_i + 1][data->pos_j] == 'C'
			|| data->map[data->pos_i + 1][data->pos_j] == 'E'
			|| data->map[data->pos_i + 1][data->pos_j] == 'N'))
			test_down(data);
	key_hook2(keycode, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	moov_enemi(data, nb);
	render(data);
	return (0);
}



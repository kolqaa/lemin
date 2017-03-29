/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:50:24 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/23 19:40:52 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		push_ant_front(int flat, int next, t_data *data)
{
	t_room	*room;
	int		name_ant;

	room = find_room_in_lst(data, flat);
	if (!room->start && room->ant)
	{
		name_ant = room->ant;
		room->ant = 0;
		if (room->end)
			data->last_room_ant++;
		room = find_room_in_lst(data, next);
		room->ant = name_ant;
		printf("L%d-%s ", name_ant, room->name);
		return (1);
	}
	return (0);
}

int		move_ant(t_data *data, char **solution, int i, int res)
{
	int j;
	int prev;

	while (solution[i])
	{
		j = (int)ft_strlen(solution[i]) - 1;
		while (j > 0)
		{
			while (ft_isdigit(solution[i][j]))
				j--;
			prev = ft_atoi(&solution[i][j + 1]);
			if (solution[i][j] == '-' && j > 0)
				j--;
			while (j > 0 && ft_isdigit(solution[i][j]))
				j--;
			if (j == 0)
			{
				res += push_ant_front(ft_atoi(&solution[i][j]), prev, data);
			}
			else
				res += push_ant_front(ft_atoi(&solution[i][j + 1]), prev, data);
		}
		i++;
	}
	return (res);
}

void	go_first_ant(char **solution, t_data *data, int *path_len)
{
	t_room	*room;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (solution[i])
	{
		j = 0;
		if (data->ants >= path_len[i] - path_len[0] && data->ants > 0)
		{
			while (ft_isdigit(solution[i][j]))
				j++;
			tmp = ft_atoi(&solution[i][j + 1]);
			room = find_room_in_lst(data, tmp);
			room->ant = data->ant_run;
			data->ants--;
			data->ant_run++;
			if (i)
				printf(" ");
			printf("L%d-%s", room->ant, room->name);
		}
		i++;
	}
}

void	go_ant(char **solution, t_data *data)
{
	int	i;
	int	*path_len;
	int	j;
	int res;

	i = 0;
	j = 0;
	res = 0;
	path_len = len_room(solution);
	while (solution[i])
	{
		printf("%s\n", solution[i]);
		i++;
	}
	i = 0;
	while (data->ants > 0 || i)
	{
		if (data->ants > 0)
			go_first_ant(solution, data, path_len);
		printf("\n");
		i = move_ant(data, solution, j, res);
	}
	free(path_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:43:16 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/29 22:28:36 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_help_short_way(t_data *data, int index, t_room *tmp, char **way)
{
	int j;

	j = 0;
	while (data->matrix[index][j])
	{
		tmp = find_room_in_lst(data, j + 1);
		if (data->matrix[index][j] == '1' && !tmp->been_there)
		{
			*way = ft_strjoin5(*way, ft_strjoin4("-", ft_itoa(j + 1)));
			data->count++;
			if (short_way(data, j, way))
				return (1);
			data->count--;
			(*way)[clear(way)] = '\0';
		}
		j++;
	}
	return (0);
}

int		short_way(t_data *data, int index, char **way)
{
	int		j;
	t_room	*tmp;

	tmp = find_room_in_lst(data, index + 1);
	tmp->been_there = 1;
	if (tmp->end)
		return (1);
	tmp = find_room_in_lst(data, data->end);
	if (data->count == tmp->len)
	{
		tmp = find_room_in_lst(data, index + 1);
		tmp->been_there = 0;
		return (0);
	}
	j = 0;
	if (ft_help_short_way(data, index, tmp, way))
		return (1);
	tmp = find_room_in_lst(data, index + 1);
	tmp->been_there = 0;
	return (0);
}

void	make_mark(t_data *data, int mtrx_room, t_room *tmp_room, int count)
{
	tmp_room = find_room_in_lst(data, mtrx_room + 1);
	if (tmp_room->len > count + 1)
		tmp_room->len = count + 1;
}

void	dkstr(t_data *data, int count, int index)
{
	int		mtrx_room;
	t_room	*tmp_room;

	tmp_room = NULL;
	mtrx_room = 0;
	while (data->matrix[index - 1][mtrx_room])
	{
		if (data->matrix[index - 1][mtrx_room] == '1')
			make_mark(data, mtrx_room, tmp_room, count);
		mtrx_room++;
	}
	if (index == data->end)
		return ;
	mtrx_room = 0;
	tmp_room = find_room_in_lst(data, index);
	tmp_room->been_there = 1;
	while (data->matrix[index - 1][mtrx_room])
	{
		tmp_room = find_room_in_lst(data, mtrx_room + 1);
		if (data->matrix[index - 1][mtrx_room] == '1' && !tmp_room->been_there)
			dkstr(data, count + 1, mtrx_room + 1);
		mtrx_room++;
	}
	tmp_room = find_room_in_lst(data, index);
	tmp_room->been_there = 0;
}

char	**find_path(t_data *data, int i)
{
	t_room	*tmp;
	char	**solution;
	char	*way;

	solution = NULL;
	tmp = NULL;
	solution = make_and_reset(data, solution);
	tmp = find_room_in_lst(data, data->end);
	tmp->len = 777;
	while (tmp->len != 999)
	{
		reset_value(data, 0);
		dkstr(data, 0, data->start);
		data->count = 0;
		way = ft_itoa(data->start);
		short_way(data, data->start - 1, &way);
		if (check_way_exist(way))
			break ;
		solution[i++] = ft_strdup(way);
		free(way);
		if (tmp->len == 1)
			data->matrix[data->start - 1][data->end - 1] = '0';
	}
	solution[i] = 0;
	return (solution);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sizes_and_clear_free.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:23:02 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/23 17:25:37 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reset_value(t_data *data, int x)
{
	t_room *tmp;

	tmp = data->room;
	while (tmp)
	{
		if (x)
		{
			tmp->been_there = 0;
			tmp->ant = 0;
		}
		if (tmp->end)
			tmp->been_there = 0;
		tmp->len = 999;
		tmp = tmp->next;
	}
}

int		clear(char **way)
{
	int i;

	i = (int)ft_strlen(*way) - 1;
	if (i > 1)
	{
		while ((*way)[i] != '-')
			i--;
		return (i);
	}
	return (1);
}

int		take_quantity(char **solution)
{
	int i;

	i = 0;
	while (solution[i])
		i++;
	return (i);
}

int		*len_room(char **solution)
{
	int *len;
	int i;
	int count;
	int j;

	i = take_quantity(solution);
	len = (int *)malloc(sizeof(int) * (i + 1));
	len[i] = 0;
	i = 0;
	while (solution[i])
	{
		j = 0;
		count = 0;
		while (solution[i][j])
		{
			if (solution[i][j] == '-')
				count++;
			j++;
		}
		len[i] = count;
		i++;
	}
	return (len);
}

int		take_index(char *line, t_data *data)
{
	int		index;
	t_room	*tmp;

	index = 1;
	tmp = data->room;
	while (tmp)
	{
		if (!ft_strcmp(line, tmp->name))
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (0);
}

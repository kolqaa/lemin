/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:11:44 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/29 20:13:16 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	take_line(t_data *data, char *line)
{
	data->out = ft_strjoin3(data->out, line);
	data->out = ft_strjoin3(data->out, "\n");
}

char	**make_and_reset(t_data *data, char **solution)
{
	data->ant_run = 1;
	solution = (char**)malloc(sizeof(char *) * (room_count(&(data->room)) + 1));
	take_start_end_index(data);
	reset_value(data, 1);
	return (solution);
}

void	free_all(char **solution, t_data *data)
{
	free_array(solution);
	free_array(data->matrix);
	free_lst(data);
	free(data->out);
	free(data);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_lst(t_data *data)
{
	t_room *tmp;
	t_room *tmp1;

	tmp = data->room;
	while (tmp)
	{
		tmp1 = tmp;
		free(tmp1->name);
		free(tmp1);
		tmp = tmp->next;
	}
}

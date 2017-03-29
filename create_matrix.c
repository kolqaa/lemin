/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:28:08 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/23 17:29:24 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_count(t_room **room)
{
	t_room	*tmp;
	int		count;

	count = 0;
	tmp = *room;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int		create_matrix(t_data *data)
{
	int size;
	int i;

	i = 0;
	size = room_count(&(data->room));
	if ((data->matrix = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (0);
	data->matrix[size] = 0;
	while (i < size)
	{
		data->matrix[i] = ft_strnew(size);
		data->matrix[i] = ft_memset(data->matrix[i], '0', size);
		i++;
	}
	return (1);
}

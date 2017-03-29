/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:33:48 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/23 18:36:21 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	write_name_in_lst(t_room **lst, char *get_name, int flag)
{
	t_room	*tmp;
	t_room	*tmp2;

	tmp = (t_room *)malloc(sizeof(*tmp));
	tmp->name = ft_strdup(get_name);
	if (flag == START)
		tmp->start = 1;
	else
		tmp->start = 0;
	if (flag == END)
		tmp->end = 1;
	else
		tmp->end = 0;
	tmp->next = NULL;
	if (*lst == NULL)
		*lst = tmp;
	else
	{
		tmp2 = *lst;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
}

void	take_start_end_index(t_data *data)
{
	t_room	*tmp;
	int		index;

	index = 1;
	tmp = data->room;
	while (tmp)
	{
		if (tmp->start)
			data->start = index;
		if (tmp->end)
			data->end = index;
		index++;
		tmp = tmp->next;
	}
}

t_room	*find_room_in_lst(t_data *data, int index)
{
	t_room	*tmp;
	int		tmpindex;

	tmp = data->room;
	tmpindex = 1;
	while (tmp)
	{
		if (index == tmpindex)
			return (tmp);
		tmpindex++;
		tmp = tmp->next;
	}
	return (NULL);
}

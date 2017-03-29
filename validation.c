/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:56:54 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/29 19:32:43 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		validate(t_data *data)
{
	if (!data->start || !data->end || !data->links || !data->flag_room)
	{
		if (data->start && data->end && data->links && !data->flag_room)
			return (1);
		if (!data->start)
			printf("ERROR:There is no start room\n");
		if (!data->end)
			printf("ERROR:There is no end room\n");
		if (!data->links)
			printf("ERROR:There is no link block\n");
		if (!data->flag_room)
			printf("ERROR:There is no room block\n");
		return (0);
	}
	return (1);
}

int		is_number(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int		not_links(char *line)
{
	if (!ft_strchr(line, '-'))
		return (1);
	return (0);
}

int		is_room(char *line)
{
	int count;
	int len;

	count = 0;
	len = (int)ft_strlen(line) - 1;
	while (len > 0 && count < 2)
	{
		while (line[len] != ' ')
		{
			if (!ft_isdigit(line[len]) && line[len] != ' ')
				return (0);
			len--;
		}
		while (line[len] == ' ')
		{
			count++;
			len--;
			if (count > 2)
			{
				printf("ERROR IS NOT ROOM FUNC\n");
				return (0);
			}
		}
	}
	return ((count == 2) ? 1 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:26:10 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/29 21:59:04 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*get_name(int index, t_data *data)
{
	t_room	*tmp;
	int		count;

	count = 1;
	tmp = data->room;
	while (tmp)
	{
		if (index == count)
			return (tmp->name);
		count++;
		tmp = tmp->next;
	}
	return (0);
}

void	show_path(char **solution, t_data *data)
{
	int		index;
	char	*name;
	int		i;
	int		j;

	i = 0;
	while (solution[i])
	{
		j = 0;
		while (solution[i][j])
		{
			if (solution[i][j] == '-')
			{
				printf("%c", solution[i][j]);
				j++;
			}
			index = ft_atoi(&solution[i][j]);
			name = get_name(index, data);
			printf("%s", name);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

int		check_way_exist(char *way)
{
	if (way[1] == '\0')
	{
		free(way);
		return (1);
	}
	return (0);
}

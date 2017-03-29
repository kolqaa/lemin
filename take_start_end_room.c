/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_start_end_room.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:07:50 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/29 20:10:46 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_valid_start(char **get_name, t_data *data, int i)
{
	if (i == 3 && is_number(get_name[1]) && is_number(get_name[2]))
	{
		if (get_name[0][0] != 'L')
		{
			write_name_in_lst(&(data->room), get_name[0], START);
			data->start = START;
			free_array(get_name);
			return (1);
		}
	}
	printf("ERROR: Room after ##start not valid\n");
	free_array(get_name);
	return (0);
}

int		take_start(char *line, t_data *data)
{
	int		i;
	char	**get_name;

	i = 0;
	if (data->start)
	{
		printf("ERROR: There must be only one ##start\n");
		return (0);
	}
	get_next_line(0, &line);
	take_line(data, line);
	if (line[0] == '#')
	{
		printf("ERROR: Not correct start\n");
		return (0);
	}
	get_name = ft_strsplit(line, ' ');
	free(line);
	while (get_name[i])
		i++;
	if (check_valid_start(get_name, data, i))
		return (1);
	return (0);
}

int		check_valid_end(char **get_name, t_data *data, int i)
{
	if (i == 3 && is_number(get_name[1]) && is_number(get_name[2]))
	{
		if (get_name[0][0] != 'L')
		{
			write_name_in_lst(&(data->room), get_name[0], END);
			data->end = END;
			free_array(get_name);
			return (1);
		}
	}
	printf("ERROR: Room after ##end not valid\n");
	free_array(get_name);
	return (0);
}

int		take_end(char *line, t_data *data)
{
	int		i;
	char	**get_name;

	i = 0;
	if (data->end)
	{
		printf("ERROR: There must be only one ##end\n");
		return (0);
	}
	get_next_line(0, &line);
	take_line(data, line);
	if (line[0] == '#')
	{
		printf("ERROR: Not correct end\n");
		return (0);
	}
	get_name = ft_strsplit(line, ' ');
	free(line);
	while (get_name[i])
		i++;
	if (check_valid_end(get_name, data, i))
		return (1);
	return (0);
}

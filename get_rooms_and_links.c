/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms_and_links.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:20:41 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/29 22:28:52 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_name(char *line, t_room **lst)
{
	t_room	*tmp;
	int		flag;

	if (lst == NULL)
		return (0);
	flag = 0;
	tmp = *lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, line))
			flag = 1;
		tmp = tmp->next;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int		check_valid(char *line, t_data *data)
{
	char	**get_name;
	int		i;

	i = 0;
	get_name = ft_strsplit(line, '-');
	while (get_name[i])
		i++;
	if (i == 2 && check_name(get_name[0], (&(data->room))) &&
		check_name(get_name[1], (&(data->room))))
	{
		data->index_x = take_index(get_name[0], data);
		data->index_y = take_index(get_name[1], data);
		data->matrix[data->index_y - 1][data->index_x - 1] = '1';
		data->matrix[data->index_x - 1][data->index_y - 1] = '1';
		data->links = 1;
		free_array(get_name);
		return (1);
	}
	printf("ERROR: Link %s-%s incorrect\n", get_name[0], get_name[1]);
	free_array(get_name);
	return (0);
}

int		get_links_from_line(char *line, t_data *data)
{
	if (data->matrix == NULL)
		create_matrix(data);
	if (!check_valid(line, data))
		return (0);
	return (1);
}

int		get_room_from_line(char *line, t_data *data)
{
	int		i;
	char	**get_name;

	get_name = ft_strsplit(line, ' ');
	i = 0;
	while (get_name[i])
		i++;
	if (i == 3 && is_number(get_name[1]) && is_number(get_name[2]))
	{
		if (get_name[0][0] != 'L')
		{
			write_name_in_lst(&(data->room), get_name[0], 0);
			data->flag_room = 1;
			free_array(get_name);
			return (1);
		}
	}
	free_array(get_name);
	printf("ERROR: %s is not room\n", line);
	return (0);
}

int		get_room_and_links(char *line, t_data *data)
{
	while (get_next_line(0, &line) > 0)
	{
		take_line(data, line);
		if (ft_strchr(line, '-') && line[0] != '#')
			if (!get_links_from_line(line, data))
				return (0);
		if (!ft_strcmp(line, "##start"))
			if (!take_start(line, data))
				return (0);
		if (!ft_strcmp(line, "##end"))
			if (!take_end(line, data))
				return (0);
		if (line[0] == '#')
			if (check_comment(line))
				continue ;
		if (!check_link_block(line, data))
			return (0);
		if (!data->links)
			if (!get_room_from_line(line, data))
				return (0);
		free(line);
	}
	free(line);
	return (1);
}

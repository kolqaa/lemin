/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:23:00 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/29 21:35:15 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_possible_solution(char **solution)
{
	if (solution[0] == '\0')
	{
		printf("ERROR: No possible solution :(\n");
		return (0);
	}
	return (1);
}

void	take_begin_of_file(char *line, t_data *data)
{
	data->out = ft_strdup(line);
	data->out = ft_strjoin3(data->out, "\n");
}

t_data	*create_struct(t_data *data)
{
	return (data);
}

int		find_way_go_ant(char **solution, t_data *data, int i)
{
	solution = find_path(data, i);
	if (!check_possible_solution(solution))
		return (0);
	printf("%s\n", data->out);
	go_ant(solution, data);
	free_all(solution, data);
	return (1);
}

int		main(void)
{
	t_data	*data;
	char	**solution;
	char	*line;
	int		i;

	i = 0;
	solution = NULL;
	data = (t_data *)malloc(sizeof(*data));
	ft_bzero(data, sizeof(*data));
	data = create_struct(data);
	get_next_line(0, &line);
	take_begin_of_file(line, data);
	if (!check_ant(line, data))
		return (0);
	free(line);
	line = NULL;
	if (!get_room_and_links(line, data))
		return (0);
	if (!validate(data))
		return (0);
	if (!find_way_go_ant(solution, data, i))
		return (0);
	return (0);
}

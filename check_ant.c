/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:37:21 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/23 18:38:26 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_ant(char *line, t_data *data)
{
	char *tmp;

	tmp = line;
	if (tmp[0] <= '0')
	{
		printf("ERROR: It should be at least 1 ant\n");
		return (0);
	}
	while (*tmp)
	{
		if (!ft_isdigit((int)*tmp))
		{
			printf("ERROR: Ants block can consist only digits\n");
			return (0);
		}
		tmp++;
	}
	data->ants = ft_atoi(line);
	return (1);
}

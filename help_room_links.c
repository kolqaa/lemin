/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_room_links.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:57:08 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/29 21:58:06 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_link_block(char *line, t_data *data)
{
	if ((data->links && is_room(line)) || (data->links && not_links(line)))
	{
		printf("ERROR: Link block incorrect\n");
		return (0);
	}
	return (1);
}

int		check_comment(char *line)
{
	free(line);
	return (1);
}

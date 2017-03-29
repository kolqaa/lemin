/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:29:56 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/28 20:04:10 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define START 1
# define END 2

typedef struct		s_room
{
	char			*name;
	int				start;
	int				len;
	int				been_there;
	int				end;
	int				ant;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	int		ants;
	int		last_room_ant;
	int		ant_run;
	int		index_y;
	int		index_x;
	int		start;
	int		end;
	char	**matrix;
	int		count;
	char	*out;
	int		fd;
	int		flag_room;
	int		links;
	t_room	*room;
}					t_data;

int					check_ant(char *line, t_data *data);
int					is_number(char *line);
int					not_links(char *line);
int					get_room_and_links(char *line, t_data *data);
int					is_room(char *line);
int					get_room_from_line(char *line, t_data *data);
void				write_name_in_lst(t_room **lst, char *get_name, int flag);
int					take_end(char *line, t_data *data);
int					take_start(char *line, t_data *data);
int					get_links_from_line(char *line, t_data *data);
int					check_valid(char *line, t_data *data);
int					check_name(char *line, t_room **lst);
int					room_count(t_room **room);
int					create_matrix(t_data *data);
t_room				*find_room_in_lst(t_data *data, int index);
void				go_ant(char **solution, t_data *data);
int					validate(t_data *data);
char				**find_path(t_data *data, int i);
void				show_path(char **solution, t_data *data);
int					clear(char **way);
void				reset_value(t_data *data, int x);
int					*len_room(char **solution);
int					take_quantity(char **solution);
int					take_index(char *line, t_data *data);
void				take_start_end_index(t_data *data);
char				*ft_strjoin3(char *s1, char *s2);
char				*ft_strjoin4(char *s1, char *s2);
char				*ft_strjoin5(char *s1, char *s2);
void				free_array(char **array);
int					short_way(t_data *data, int index, char **way);
char				**make_and_reset(t_data *data, char **solution);
void				free_lst(t_data *data);
void				free_all(char **solution, t_data *data);
void				take_line(t_data *data, char *line);
int					check_link_block(char *line, t_data *data);
int					check_comment(char *line);
int					check_way_exist(char *way);

#endif

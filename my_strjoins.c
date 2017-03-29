/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:11:05 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/29 20:11:24 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*ft_strjoin3(char *s1, char *s2)
{
	int		j;
	int		k;
	int		lens1;
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (s1[k])
		str[j++] = s1[k++];
	k = 0;
	while (s2[k])
		str[lens1++] = s2[k++];
	str[lens1] = '\0';
	free(s1);
	return (str);
}

char	*ft_strjoin4(char *s1, char *s2)
{
	int		j;
	int		k;
	int		lens1;
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (s1[k])
		str[j++] = s1[k++];
	k = 0;
	while (s2[k])
		str[lens1++] = s2[k++];
	str[lens1] = '\0';
	free(s2);
	return (str);
}

char	*ft_strjoin5(char *s1, char *s2)
{
	int		j;
	int		k;
	int		lens1;
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (s1[k])
		str[j++] = s1[k++];
	k = 0;
	while (s2[k])
		str[lens1++] = s2[k++];
	str[lens1] = '\0';
	free(s2);
	free(s1);
	return (str);
}

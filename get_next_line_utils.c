/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:20:12 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/02 15:00:28 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	next_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	free(s2);
	return (res);
}

char	*ft_strndup(char *s1, int n)
{
	char	*res;
	int		i;

	if (ft_strlen(s1) < n)
		res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	else
		res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

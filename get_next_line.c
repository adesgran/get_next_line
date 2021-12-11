/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:04:35 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/07 18:20:40 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_nl(char *s)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (!res)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\n';
	res[i + 1] = '\0';
	free(s);
	return (res);
}

char	*read_buffer(char **buffer)
{
	char	*res;
	char	*new_buff;
	int		next;
	int		len;

	if (*buffer == NULL)
		return (NULL);
	len = ft_strlen(*buffer);
	next = next_nl(*buffer);
	if (next == -1)
	{
		res = ft_strndup(*buffer, ft_strlen(*buffer));
		new_buff = NULL;
	}
	else
	{
		res = ft_strndup(*buffer, next + 1);
		new_buff = ft_strndup(*buffer + next + 1, len);
	}
	free(*buffer);
	*buffer = new_buff;
	return (res);
}

char	*fill_buffer(char *s, char **buff)
{
	int		len;
	int		len_s;
	char	*res;

	if (!s || !buff)
		return (NULL);
	len = next_nl(s);
	len_s = ft_strlen(s);
	res = ft_strndup(s, len + 1);
	if (len_s > len + 1)
	{
		*buff = ft_strndup(s + len + 1, len_s - len + 1);
		if (!buff)
		{
			free(res);
			free(s);
			return (NULL);
		}
	}
	free(s);
	return (res);
}

char	*fill_line(int fd, char *s, char **buff)
{
	char	*buffer;
	int		n_char;
	char	*temp;

	buffer = malloc(sizeof(char) * ((long)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	n_char = read(fd, buffer, BUFFER_SIZE);
	if (n_char <= 0)
	{
		free(*buff);
		free(buffer);
		if (n_char == 0)
			return (s);
		free(s);
		return (NULL);
	}
	buffer[n_char] = '\0';
	if (next_nl(buffer) == -1)
		temp = fill_line(fd, ft_strjoin_free(s, buffer), buff);
	else
		temp = ft_strjoin_free(s, fill_buffer(buffer, buff));
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stat_buff;
	char		*line;

	if (stat_buff)
	{
		line = read_buffer(&stat_buff);
		if (!line)
			return (NULL);
	}
	else
	{
		line = ft_strndup("", 1);
		if (!line)
			return (NULL);
	}
	if (next_nl(line) == -1)
		line = fill_line(fd, line, &stat_buff);
	if (!line)
		return (NULL);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:57:05 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/02 14:51:08 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strndup(char *s, int n);
char	*read_buffer(char **buffer);
int		next_nl(char *s);
char	*ft_strjoin_free(char *s1, char *s2);
char	*add_nl(char *s);
char	*fill_buffer(char *s, char **buff);
char	*fill_line(int fd, char *s, char **buff);

#endif

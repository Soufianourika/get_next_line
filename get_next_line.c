/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:50:12 by sbourziq          #+#    #+#             */
/*   Updated: 2023/12/05 15:31:49 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*helper(char *st_buff, int j)
{
	char	*save;
	char	*rest;

	save = ft_strdup(st_buff);
	rest = ft_substr(st_buff, 0, j + 1);
	free(st_buff);
	st_buff = ft_strdup(save + j + 1);
	free(save);
	return (rest);
}

char	*while_loop(int j, ssize_t bytread, int fd)
{
	static char	*st_buff;
	char		*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	bytread = read(fd, buff, BUFFER_SIZE);
	while (bytread > 0 || (st_buff && st_buff[0] != '\0'))
	{
		j = 0;
		buff[bytread] = '\0';
		st_buff = ft_strjoin(st_buff, buff);
		while (st_buff && st_buff[j] != '\0')
		{
			if (st_buff[j] == '\n')
				return (free(buff), helper(st_buff, j));
			j++;
		}
		if (bytread <= 0)
			break ;
		bytread = read(fd, buff, BUFFER_SIZE);
	}
	if (bytread == 0 && st_buff && (st_buff)[0] != '\0')
		return (free(buff), helper(st_buff, j));
	return ( NULL);
}

char	*get_next_line(int fd)
{
	int		j;
	ssize_t	bytread;
	char	*result;

	j = 0;
	bytread = 1;
	if (fd < 0 || fd > 1024)
		return (NULL);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	result = while_loop(j, bytread, fd);
	return (result);
}

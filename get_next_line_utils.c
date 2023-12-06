/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:04:13 by sbourziq          #+#    #+#             */
/*   Updated: 2023/12/03 21:13:26 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_loops(char *str, char const *buff, int i)
{
	while (buff[i] != '\0')
	{
		str[i] = buff[i];
		i++;
	}
}

static void	ft_loops2(char *str, char const *st_buff, int count, int i)
{
	while (st_buff[i] != '\0')
	{
		str[count + i] = st_buff[i];
		i++;
	}
}

char	*ft_strjoin(char const *st_buff, char const *buff)
{
	int		i;
	int		count;
	char	*str;
	int		len;

	i = 0;
	if (st_buff == NULL && buff == NULL)
		return (NULL);
	if (st_buff == NULL)
		return (ft_strdup(buff));
	else
		count = ft_strlen(st_buff);
	if (buff == NULL)
		return (ft_strdup(st_buff));
	else
		len = ft_strlen(buff);
	str = (char *)malloc(count + len + 1);
	if (str == NULL)
		return (NULL);
	ft_loops(str, st_buff, i);
	i = 0;
	ft_loops2(str, buff, count, i);
	str[count + len] = '\0';
	return (free((void *)st_buff), str);
}

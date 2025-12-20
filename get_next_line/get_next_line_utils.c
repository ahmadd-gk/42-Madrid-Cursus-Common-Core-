/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:18:25 by ahgutier          #+#    #+#             */
/*   Updated: 2025/12/20 20:39:24 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

ssize_t	ft_find_newline(char *s)
{
	size_t i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}

char	*ft_init_stash(const char *buff)
{
	size_t	len;
	char	*new;

	if (!buff)
		return (NULL);
	len = ft_strlen((char *)buff);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strlcpy_gnl(new, buff, len + 1);
	return (new);
}

char *ft_strjoin_gnl(char *stash, char const *buff)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!buff)
	    return (stash);
	if (!stash)
		return (ft_init_stash(buff));
	len1 = ft_strlen(stash);
	len2 = ft_strlen(buff);
	res = malloc(len1 + len2 + 1);
	if (!res)
	{
		free(stash);
		return (NULL);
	}
	ft_strlcpy_gnl(res, stash, len1 + 1);
	ft_strlcpy_gnl(res + len1, buff, len2 + 1);
	free(stash);
	return (res);
}

char *ft_extract_line(char *stash)
{
	char	*line;
	int nl_index;
	int i;

	if (!stash || !stash[0])
		return (NULL);
	nl_index = ft_find_newline(stash);
	if (nl_index == -1)
		nl_index = ft_strlen(stash);
	line = malloc(nl_index + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (i <= nl_index && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

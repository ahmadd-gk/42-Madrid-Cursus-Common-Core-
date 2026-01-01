/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:18:25 by ahgutier          #+#    #+#             */
/*   Updated: 2025/12/20 20:48:57 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init_stash(const char *buff)
{
	size_t	len;
	char	*new_stash;

	if (!buff)
		return (NULL);
	len = ft_strlen((char *)buff);
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (NULL);
	ft_strlcpy_gnl(new_stash, buff, len + 1);
	return (new_stash);
}

ssize_t	ft_find_newline(char *s)
{
	size_t	i;

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

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:36:59 by ahgutier          #+#    #+#             */
/*   Updated: 2025/11/19 16:36:59 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*stash;

	stash = NULL;
	stash = ft_read_stash(fd, stash);
}

char	*update_stash(char	*stash)
{
	char	*new_stashbaby;
	int		nl_index;
	int		i;
	int		j;

	nl_index = ft_find_newline(stash);
	if (nl_index == -1)
	{
		free(stash);
		return (NULL);
	}
	new_stashbaby = malloc(ft_strlen(stash) - nl_index);
	if (!new_stashbaby)
		return (NULL);
	i = nl_index + 1; // Para que se salte el '\n' NO para ell null terminator
	while (stash[i])
		new_stashbaby[j++] = stash[i++];
	new_stashbaby[j] = '\0';
	free(stash);
	return (new_stashbaby);
}

size_t	ft_strlcpy_gnl(char	*dst, char	*src, size_t	size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
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

char	*ft_read_stash(int	fd, char	*stash)
{
	char	*buff[BUFFER_SIZE + 1];
	ssize_t	*bytes_read;

	bytes_read = read(fd, buff, BUFFER_SIZE);
}

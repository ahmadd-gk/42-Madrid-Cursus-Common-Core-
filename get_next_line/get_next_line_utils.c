/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:18:25 by ahgutier          #+#    #+#             */
/*   Updated: 2025/11/25 18:18:25 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

ssize_t	find_newline(char	*s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_str_join_free_stash(char	*stash, char	const *buff)
{
	char	*res;
	char	*ptr_end;
	char	*orig_stash_dir;
	size_t	len1;
	size_t	len2;

	if (!buff)
		return (NULL);
	if (!stash)
		if_not_stash(stash, buff);
	len1 = ft_strlen(stash);
	len2 = ft_strlen(buff);
	orig_stash_dir = stash;
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ptr_end = res;
	while (*stash)
		*ptr_end++ = *stash++;
	while (*buff)
		*ptr_end++ = *buff++;
	*ptr_end = '\0';
	free (orig_stash_dir);
	return (res);
}

char	*if_not_stash(char	*stash, char	const *buff)
{
	char	*mover;

	stash = malloc(ft_strlen(buff) + 1);
	if (!stash)
		return (NULL);
	mover = stash;
	while (*buff)
		*mover++ = *buff++;
	*mover = '\0';
	return (stash);
}

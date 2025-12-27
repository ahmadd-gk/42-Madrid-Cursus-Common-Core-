/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:36:59 by ahgutier          #+#    #+#             */
/*   Updated: 2025/12/20 20:47:35 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_update_stash(stash);
	return (line);
}

char	*ft_update_stash(char *stash)
{
	char	*new_stash;
	int		nl_index;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	nl_index = ft_find_newline(stash);
	if (nl_index == -1)
	{
		free (stash);
		return (NULL);
	}
	len = ft_strlen(stash);
	new_stash = malloc(len - nl_index);
	if (!new_stash)
		return (NULL);
	i = (size_t)nl_index + 1;
	j = 0;
	while (i < len)
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
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

char	*ft_read_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (ft_find_newline(stash) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), free(stash), NULL);
		buf[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

// Sacar todo el texto del archivo
/* int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
	{
		write(2, "Usage: ./a.out <file>\n", 23);
		return (1);
	}

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
} */

// Hasta una línea en específica
/* int main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;
	int		n;

	if (ac != 3)
		return (1);
	fd = open(av[1], O_RDONLY);
	n = atoi(av[2]); // SOLO EN MAIN, nunca en GNL
	i = 0;
	while (i < n)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
} */

// Sacar una sola línea en concreto
/* int main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;
	int		target;

	if (ac != 3)
		return (1);
	fd = open(av[1], O_RDONLY);
	target = atoi(av[2]);
	i = 1;
	while (i <= target)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i == target)
			printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
} */

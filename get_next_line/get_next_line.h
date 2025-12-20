/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:15:08 by ahgutier          #+#    #+#             */
/*   Updated: 2025/12/01 19:48:35 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char const	*s);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
ssize_t	ft_find_newline(char	*s);
char	*get_next_line(int fd);
char	*ft_read_stash(int	fd, char	*stash);
char	*ft_strjoin_gnl(char *stash, char const *buff);
char	*ft_extract_line(char   *stash);
char	*ft_update_stash(char   *stash);
char 	*ft_init_stash(char const *buff);

#endif

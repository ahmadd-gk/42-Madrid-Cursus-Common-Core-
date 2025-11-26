/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:15:08 by ahgutier          #+#    #+#             */
/*   Updated: 2025/11/25 18:15:08 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#define BUFFER_SIZE 42

char	*get_next_line(int fd);
size_t	ft_strlen(char	*s);
ssize_t	find_newline(char	*s);

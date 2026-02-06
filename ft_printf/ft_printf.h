/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:02:08 by ahgutier          #+#    #+#             */
/*   Updated: 2026/01/10 17:02:08 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
// # include <stdio.h>

int		ft_printf(const char *format, ...);

int		handle_format_parser(char specifier, va_list *args);
int		handle_percent(void);
int		handle_char(va_list *args);
int		handle_string(va_list *args);
int		handle_decimal(va_list *args);
int		handle_unsigned(va_list *args);
int		handle_pointer(va_list *args);
int		handle_hex(va_list *args, char spec);
int		fill_hex_buf(unsigned int n, char *buf, char *base);

void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	ft_putnbr_base(unsigned long n, char *base);

#endif

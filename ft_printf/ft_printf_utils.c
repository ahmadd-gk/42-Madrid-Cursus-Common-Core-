/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:34:22 by ahgutier          #+#    #+#             */
/*   Updated: 2026/01/11 19:34:22 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = (long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd((int)(nb / 10), fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	ft_putchar_fd(base[n % base_len], 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_cases2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:23:33 by ahgutier          #+#    #+#             */
/*   Updated: 2026/01/11 19:23:33 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_unsigned(va_list *args)
{
	unsigned int	n;
	unsigned int	tmp;
	int				count;

	n = va_arg(*args, unsigned int);
	ft_putnbr_unsigned_fd(n, 1);
	if (n == 0)
		return (1);
	count = 0;
	tmp = n;
	while (tmp)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

int	handle_pointer(va_list *args)
{
	unsigned long long	ptr;
	unsigned long long	tmp;
	int					count;

	ptr = (unsigned long long)va_arg(*args, void *);
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(ptr, "0123456789abcdef");
	count = 2;
	tmp = ptr;
	while (tmp)
	{
		tmp /= 16;
		count++;
	}
	return (count);
}

int	handle_hex(va_list *args, char spec)
{
	unsigned int	n;
	char			*base;
	char			buf[16];
	int				i;
	int				count;

	n = va_arg(*args, unsigned int);
	if (spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n > 0)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	count = i;
	while (--i >= 0)
		write(1, &buf[i], 1);
	return (count);
}

int	fill_hex_buf(unsigned int n, char *buf, char *base)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		buf[i++] = '0';
		return (i);
	}
	while (n)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	return (i);
}

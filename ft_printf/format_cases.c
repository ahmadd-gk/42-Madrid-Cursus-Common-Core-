/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:05:06 by ahgutier          #+#    #+#             */
/*   Updated: 2026/01/11 19:05:06 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	handle_char(va_list *args)
{
	ft_putchar_fd(va_arg(*args, int), 1);
	return (1);
}

int	handle_string(va_list *args)
{
	char	*str;
	int		count;

	str = va_arg(*args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	count = 0;
	while (str[count])
		ft_putchar_fd(str[count++], 1);
	return (count);
}

int	handle_decimal(va_list *args)
{
	long	n;
	long	tmp;
	int		count;

	n = va_arg(*args, int);
	ft_putnbr_fd(n, 1);
	count = 0;
	if (n <= 0)
		count++;
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	while (tmp)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

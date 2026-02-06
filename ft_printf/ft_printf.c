/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahgutier <ahgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:56:47 by ahgutier          #+#    #+#             */
/*   Updated: 2026/01/04 18:56:47 by ahgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format_parser(char specifier, va_list *args)
{
	if (specifier == '%')
		return (handle_percent());
	if (specifier == 'c')
		return (handle_char(args));
	if (specifier == 's')
		return (handle_string(args));
	if (specifier == 'd' || specifier == 'i')
		return (handle_decimal(args));
	if (specifier == 'u')
		return (handle_unsigned(args));
	if (specifier == 'p')
		return (handle_pointer(args));
	if (specifier == 'x' || specifier == 'X')
		return (handle_hex(args, specifier));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		tmp;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
			count += write(1, format++, 1);
		else if (!*++format)
			return (count + write(1, "%", 1));
		else
		{
			tmp = handle_format_parser(*format, &args);
			count += tmp;
			format++;
		}
	}
	va_end(args);
	return (count);
}

/* int	main()
{
	ft_printf("%s %d\n", "Hola, ", 42);
	ft_printf("%s, %d\n", "Hi", 42);
	printf("REAL  : |%q|\n", 42);
	ft_printf("MIO   : |%q|\n", 42);

	printf("REAL  : |%%|\n");
	ft_printf("MIO   : |%%|\n");

	printf("REAL  : |%|\n");
	ft_printf("MIO   : |%|\n");

	printf("REAL  : |%p|\n", NULL);
	ft_printf("MIO   : |%p|\n", NULL);

	ft_printf("Hola %d, %s %c", 42, "cómo te encuentras en", 'C');
	ft_printf("\nhola %");
} */

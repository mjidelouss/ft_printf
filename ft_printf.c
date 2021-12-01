/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:17:39 by aelousse          #+#    #+#             */
/*   Updated: 2021/12/01 22:25:40 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print(char c, va_list ptr, int *n)
{
	if (c == '%')
		(*n) += ft_putchar_fd('%', 1);
	else if (c == 'c')
		(*n) += ft_putchar_fd(va_arg(ptr, int), 1);
	else if (c == 's')
		(*n) += ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (c == 'd' || c == 'i')
		(*n) += ft_putnbr(va_arg(ptr, int));
	else if (c == 'p')
		(*n) += ft_putlnbr(va_arg(ptr, void *));
	else if (c == 'u')
		ft_putu(va_arg(ptr, unsigned int), n);
	else if (c == 'x')
		ft_puthex(va_arg(ptr, unsigned int), "0123456789abcdef", n);
	else if (c == 'X')
		ft_puthex(va_arg(ptr, unsigned int), "0123456789ABCDEF", n);
}

int	ft_printf(const char *format, ...)
{
	int		n;
	va_list	ptr;

	n = 0;
	va_start(ptr, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_print(*format, ptr, &n);
		}
		else
			n += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ptr);
	return (n);
}

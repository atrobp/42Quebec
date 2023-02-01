/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:17:49 by atopalli          #+#    #+#             */
/*   Updated: 2022/08/12 10:15:29 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftputchar(char c, int *counter);
void	ftputstr(const char *str, int *counter);
void	p2str(unsigned long num, int *counter);
void	int2str(unsigned int num, char wbase, int base, int *counter);

int	ft_printf(const char *format, ...)
{
	t_list	p;

	va_start(p.arg, format);
	p.aint = 0;
	while (*format)
	{
		if (*format == '%' && format++)
		{
			if (*format == 'c')
				ftputchar(va_arg(p.arg, int), &p.aint);
			else if (*format == 's')
				ftputstr(va_arg(p.arg, char *), &p.aint);
			else if (*format == 'p')
				p2str(va_arg(p.arg, long), &p.aint);
			else if (*format == '%')
				ftputstr("%", &p.aint);
			else
				int2str(va_arg(p.arg, int), *format, 10, &p.aint);
			format++;
		}
		else
			ftputchar(*format++, &p.aint);
	}
	return (p.aint);
}

void	p2str(unsigned long num, int *counter)
{
	static char	allbase[16] = "0123456789abcdef";
	char		*str;
	char		buff[50];

	str = &buff[49];
	*str = '\0';
	ftputstr("0x", counter);
	if (num != 0)
	{
		while (num)
		{
			*--str = allbase[num % 16];
			num /= 16;
		}
		while (*str)
			ftputchar(*str++, counter);
		return ;
	}
	ftputchar('0', counter);
}

void	int2str(unsigned int num, char wbase, int base, int *counter)
{
	static char	allbase[16] = "0123456789abcdef";
	char		*str;
	char		buff[50];

	str = &buff[49];
	*str = '\0';
	if (wbase == 'x' || wbase == 'X')
		base = 16;
	if ((wbase == 'i' || wbase == 'd') && (int)num < 0)
	{
		num = (int)-num;
		ftputstr("-", counter);
	}
	if (num == 0)
		*--str = '0';
	while (num && num != 0)
	{
		if (wbase == 'X' && num % base > 9)
			*--str = allbase[num % base] - 32;
		else
			*--str = allbase[num % base];
		num /= base;
	}
	while (*str)
		ftputchar(*str++, counter);
}

void	ftputstr(const char *str, int *counter)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
		ftputchar(*str++, counter);
}

void	ftputchar(char c, int *counter)
{
	write(1, &c, 1);
	*counter += 1;
}

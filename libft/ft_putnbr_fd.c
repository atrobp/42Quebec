/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:36:03 by atopalli          #+#    #+#             */
/*   Updated: 2022/04/04 14:36:03 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	int	isneg(int n);
static	void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
		ft_putchar_fd('-', fd);
	num = isneg(n);
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}

static	int	isneg(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}
static	void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

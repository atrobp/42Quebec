/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:45:05 by atopalli          #+#    #+#             */
/*   Updated: 2022/04/04 14:45:05 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_putstr_fd(char const *s, int fd);
static	void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

static	void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i += 1;
		}
	}
	return ;
}

static	void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

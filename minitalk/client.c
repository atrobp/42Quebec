/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:33:55 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/02 13:14:51 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int		ftatoi(const char *str);

void	char2bin(char ascii, int pid)
{
	if (ascii > 0)
	{
		kill(pid, SIGUSR1);
		usleep(30);
		char2bin(ascii - 1, pid);
	}
	kill(pid, SIGUSR2);
	usleep(25);
}

void	str2char(const char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && ++i)
		{
			if (str[i] == 'n')
				char2bin(10, pid);
			else if (str[i] == 't')
				char2bin(9, pid);
			else
				char2bin('\\', pid);
			++i;
		}
		char2bin(str[i], pid);
		i += 1;
	}
}

int	main(int argc, char const *argv[])
{
	static int	i = -1;

	if (argc > 3)
		write(1, "too much args", 13);
	else if (argc < 3)
		write(1, "not enough args", 15);
	else
	{
		while (argv[1][++i])
		{
			if (argv[1][i] < '0' || argv[1][i] > '9')
			{
				printf("check pid");
				return (0);
			}
		}
		str2char(argv[2], ftatoi(argv[1]));
		printf("Received: %s", argv[2]);
	}
	return (0);
}

int	ftatoi(const char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		num = num * 10 + (*str - 48);
		str += 1;
	}
	return (num);
}

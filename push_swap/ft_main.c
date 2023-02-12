/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:35:45 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/11 23:43:51 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int ac, char *av[])
{
	t_struct	s;

	s.stacka = NULL;
	s.stackb = NULL;
	s.stacka_size = 0;
	s.stackb_size = 0;
	if (ft_check_args(av, ac, &s) == 1)
	{
		if (ft_check_stack(s.stacka_size, 'o', &s) == 1)
			ft_decide_next(&s);
		free(s.stacka);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}

void	ft_split(char *str, int *array)
{
	char		*temp;
	int			i;
	static int	index = 0;

	temp = malloc(sizeof(temp) * 11);
	if (temp)
	{
		i = 0;
		while (1)
		{
			temp[i] = *str;
			if (*str <= 32)
			{
				temp[i] = 0;
				array[index] = ft_atoi(temp, array);
				i = -1;
				index += 1;
			}
			if (*str == 0)
				break ;
			i += 1;
			str += 1;
		}
		free(temp);
	}
}

int	ft_atoi(char *str, int *stack)
{
	long	num;
	int		is_neg;

	num = 0;
	is_neg = 1;
	if (str[0] == '-')
	{
		is_neg = -1;
		str += 1;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str += 1;
	}
	if (*str || num < INT_MIN || num > INT_MAX)
	{
		ft_errorfound(stack);
	}
	return ((int)num * is_neg);
}

void	ft_errorfound(int *stack)
{
	write(2, "Error\n", 6);
	free(stack);
	exit(0);
}

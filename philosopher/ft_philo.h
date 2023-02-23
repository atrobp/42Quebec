/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@42.quebec.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:48:56 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/23 00:55:01 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_list
{
	int				philo;
	pthread_t		*tid;
	pthread_mutex_t	*phork;
	int				n_philo;
	int				*tt_die_index;
	int				t2die;
	int				t2eat;
	int				t2sleep;
	int				t_must_eat;
}	t_list;

typedef struct s_philo
{
	int	n_philo;

}

int		ft_atoi(char *str);
void	ft_philo_init(t_list *p);
bool	ft_philo_check(t_list *p, int ac, char **av);
void	*ft_philosopher(void *arg);

#endif

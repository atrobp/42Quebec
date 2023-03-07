/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.h                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli atopalli@student.42quebec.com     ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/06 20:23:47 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/07 01:12:46 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	unsigned int	philo_id;
	unsigned long	last_meal;
	unsigned int	eat_time;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	unsigned int	nbr_philo;
	unsigned int	t2die;
	unsigned int	t2eat;
	unsigned int	t2sleep;
	unsigned int	n_must_eat;
	unsigned long	start;
	bool			is_dead;
	pthread_mutex_t	sleeping;
	pthread_mutex_t	eating;
	pthread_mutex_t	writing;
	t_philo			*philos;
}					t_info;

// UTILS.C
int					ft_atoi(const char *str);
void				ft_gettime(unsigned long *number);

// INIT.C
int					ft_initinfo(t_info *info, const char **av);
int					ft_initmutex_threads(t_info *info);

// PHILO.C
void				*ft_routine(void *info);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.h                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/28 13:52:53 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/30 14:28:58 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	unsigned int	philo_id;
	unsigned int	eaten;
	unsigned long	last_meal;
	pthread_t		thread;
	pthread_mutex_t	own_fork;
	pthread_mutex_t	*neigtbour_fork;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	unsigned int	nbr_philo;
	unsigned int	time2die;
	unsigned int	time2eat;
	unsigned int	time2sleep;
	int				nbr_eat;
	bool			end;
	unsigned long	start;
	pthread_mutex_t	writing;
	t_philo			*philos;
}					t_info;

// utils

int					ft_atoi(const char *str);
unsigned long		ft_getcurrenttime(void);
void				ft_sleeptimer(unsigned int time);
void				ft_freeall(t_info *info);
bool				ft_checkdead(t_philo *philo);

// init.c

int					ft_initinfo(t_info *info, const char **str);
int					ft_initmutex(t_info *info);
int					ft_initthreads(t_info *info);

// routine.c

void				ft_eat(t_philo *philo);
void				*ft_routine(void *arg);
void				ft_reaper(t_info *info);
void				ft_think(t_philo *philo);
void				ft_print(t_philo *philo, unsigned int id,
						const char *action);

#endif

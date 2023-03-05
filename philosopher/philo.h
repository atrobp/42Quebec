/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.h                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/04 20:04:41 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/04 22:37:22 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	n_eat;
	unsigned int	last_eat;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	n_eat;
	unsigned int	start;
	t_philo			*philo;
	pthread_mutex_t	eat;
	pthread_mutex_t	print;
	pthread_mutex_t	sleep;
}					t_data;

//  main.c
unsigned int		ft_atoi(const char *str);
void				ft_print(t_philo *philo, unsigned int id, char *str);
unsigned int		ft_gettime(void);

//  init.c
unsigned int		ft_initdata(t_data *data, const char *argv[]);
unsigned int		ft_initmutex(t_data *data);
unsigned int		ft_initthreads(t_data *data);

//  philo.c
void				*ft_philo(void *arg);
void				ft_eat(t_data *data);
void				ft_sleep(t_philo *philo);
void				ft_think(t_data *data);

#endif

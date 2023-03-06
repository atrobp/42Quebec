/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.h                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/04 20:04:41 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/06 16:26:25 by atopalli            ╚═╝╚══════╝.qc       */
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
	unsigned long	last_eat;
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
	unsigned long	start;
	unsigned int	is_dead;
	t_philo			*philo;
	pthread_mutex_t	eat;
	pthread_mutex_t	print;
	pthread_mutex_t	sleep;
	pthread_mutex_t	dead;
	pthread_t		chec_dead;
}					t_data;

//  main.c
unsigned int		ft_atoi(const char *str);
unsigned long		ft_gettime(void);
void				ft_print(t_philo *philo, char *str);

//  init.c
unsigned int		ft_initdata(t_data *data, const char *argv[]);
void				ft_initphilo(t_data *data);
unsigned int		ft_initmutex(t_data *data);
unsigned int		ft_initthreads(t_data *data);

//  philo.c
void				*ft_philo(void *arg);
int					ft_eat(t_philo *philo);
int					ft_sleep(t_philo *philo);
int					ft_think(t_philo *philo);
void				ft_usleep(unsigned int time);
void				*ft_tread_chec_dead(void *arg);

#endif

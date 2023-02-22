#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 20

pthread_mutex_t	chopsticks[NUM_PHILOSOPHERS];
int				have_eat[NUM_PHILOSOPHERS];
pthread_t		philosophers[NUM_PHILOSOPHERS];
int				death_counter = 0;

void	*ft_sleep(void *threadid)
{
	long	tid;
	long	i;

	i = 0;
	tid = (long)threadid;
	pthread_mutex_lock(&chopsticks[tid]);
	printf("Philosopher %ld is sleeping.\n", tid + 1);
	while (i < 0xFFFF)
	{
		i += 1;
	}
	pthread_mutex_unlock(&chopsticks[tid]);
}

void	*ft_eating(void *threadid)
{
	long	tid;
	long	i;

	i = 0;
	tid = (long)threadid;
	pthread_mutex_lock(&chopsticks[tid]);
	printf("---->%d\n", have_eat[tid]);
	have_eat[tid] -= 1;
	printf("Philosopher %ld has both chopsticks.\n", tid + 1);
	printf("Philosopher %ld is eating.\n", tid + 1);
	while (i < 0xFFFFF)
	{
		i += 1;
	}
	pthread_mutex_unlock(&chopsticks[tid]);
}

void	*philosopher(void *threadid)
{
	long	tid;

	tid = (long)threadid;
	while (1)
	{
		printf("Philosopher %ld is thinking.\n", tid + 1);
		sleep(rand() % 2);
		ft_eating((void *)tid);
		sleep(rand() % 2);
		ft_sleep((void *)tid);
		sleep(rand() % 2);
		if (have_eat[tid] < 1)
		{
			printf("Philosopher %ld is DEAD ------------------------------.\n",
					tid + 1);
			death_counter += 1;
			break ;
		}
		sleep(rand() % 2);
	}
	printf("\n%d\n", death_counter);
	pthread_exit(NULL);
}

int	main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		pthread_mutex_init(&chopsticks[i], NULL);
	}
	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		have_eat[i] = 5;
	}
	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		pthread_create(&philosophers[i], NULL, philosopher, (void *)i);
	}
	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		pthread_join(philosophers[i], NULL);
	}
	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		pthread_mutex_destroy(&chopsticks[i]);
	}
	pthread_exit(NULL);
}

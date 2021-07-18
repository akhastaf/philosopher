/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:28:58 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/18 12:35:46 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>
# include "utils.h"
# define TAKE_FORK " has taken a fork"
# define EATING " is eating"
# define SLEEPING " is sleeping"
# define THINKING " is thinking"
# define DIED " died"
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_rules
{
	unsigned int		number_philos;
	unsigned int		time_to_die;
	unsigned int		time_to_sleep;
	unsigned int		time_to_eat;
	int					meals;
	unsigned long int	time;
}						t_rules;

typedef struct s_philo
{
	pid_t			id;
	pthread_t		monitor;
	sem_t			*eating;
	size_t			index;
	int				eated_meals;
	int				is_eating;
	size_t			last_time_eat;
	t_rules			*rules;
	sem_t			*forks;
	sem_t			*display;
}					t_philo;

typedef struct s_info
{
	t_philo	*philos;
	t_rules	*rules;
	sem_t	*forks;
	sem_t	*display;
}			t_info;

void				philo_life(t_philo *philo);
unsigned long int	ft_get_time(t_philo *philo);
void				handle_message(t_philo *philo, char *message, char *c);
void				*monitor(void *philo);
int					check_digits(int ac, char **av);
void				ft_wait(t_info *info);
int					init_philos(t_info *info);
void				init_data(t_info *info, int ac, char **av);
int					check_args(t_info *info, int ac, char **av);
#endif

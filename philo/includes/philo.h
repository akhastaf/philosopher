#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include "utils.h"
# define TO_MICRO(x) (x * 1000)
# define TO_MILI(x) (x / 1000)
# define TAKE_FORK " has taken a fork"
# define EATING " is eating"
# define SLEEPING " is sleeping"
# define THINKING " is thinking"
# define DIED " died"

typedef struct s_rules
{
    unsigned int        number_philos;
    unsigned int        time_to_die;
    unsigned int        time_to_sleep;
    unsigned int        time_to_eat;
    int                 meals;
    unsigned long int   time;
}   t_rules;

typedef struct s_philo
{
    pthread_t       id;
    pthread_mutex_t *forks;
    pthread_mutex_t *display;
    t_rules         *rules;
    unsigned int    index;
    int             eated_meals;
    int             is_eating;
    unsigned long int last_time_eat;

}                   t_philo;

typedef struct s_info
{
    t_rules *rules;
    t_philo *philos;
    pthread_t       supervisor;
    pthread_mutex_t *forks;
    pthread_mutex_t display;
}   t_info;

void*    philo_life(void *philo);
void    handle_message(t_philo *philo, char *message);
void    *supervisor(void *info);
#endif
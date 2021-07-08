/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:55:29 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/08 18:22:09 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    get_left_right(t_philo *philo, int *left, int *right)
{
    *left = philo->index - 1;
    if (philo->index == philo->rules->number_philos)
        *right = 0;
    else
        *right = philo->index;
}

void*    philo_life(void *philo)
{
    int left;
    int right;
    
    while (1)
    {
        get_left_right(philo, &left, &right);
        pthread_mutex_lock(&((t_philo *)philo)->forks[left]);
        pthread_mutex_lock(&((t_philo *)philo)->forks[right]);
        handle_message(philo, TAKE_FORK);
        handle_message(philo, TAKE_FORK);
        handle_message(philo, EATING);
        ((t_philo *)philo)->eated_meals++;
        ((t_philo *)philo)->is_eating = 1;
        usleep(TO_MICRO(((t_philo *)philo)->rules->time_to_eat));
        pthread_mutex_unlock(&((t_philo *)philo)->forks[left]);
        pthread_mutex_unlock(&((t_philo *)philo)->forks[right]);
        ((t_philo *)philo)->is_eating = 0;
        handle_message(philo, SLEEPING);
        usleep(TO_MICRO(((t_philo *)philo)->rules->time_to_sleep));
        handle_message(philo, THINKING);
    }
    return NULL;
}
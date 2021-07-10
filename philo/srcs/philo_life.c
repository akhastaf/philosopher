/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:55:29 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/10 18:16:30 by akhastaf         ###   ########.fr       */
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
    
    if (((t_philo *)philo)->index % 2 == 0)
        usleep(100);
    while (1)
    {
        get_left_right(philo, &left, &right);
        pthread_mutex_lock(&((t_philo *)philo)->forks[left]);
        handle_message(philo, TAKE_FORK, KBLU);
        pthread_mutex_lock(&((t_philo *)philo)->forks[right]);
        handle_message(philo, TAKE_FORK, KBLU);
        handle_message(philo, EATING, KGRN);
        pthread_mutex_lock(&((t_philo *)philo)->eating);
        ((t_philo *)philo)->is_eating = 1;
        usleep(TO_MICRO(((t_philo *)philo)->rules->time_to_eat));
        pthread_mutex_unlock(&((t_philo *)philo)->eating);
        ((t_philo *)philo)->eated_meals++;
        ((t_philo *)philo)->last_time_eat = get_time();
        pthread_mutex_unlock(&((t_philo *)philo)->forks[left]);
        pthread_mutex_unlock(&((t_philo *)philo)->forks[right]);
        ((t_philo *)philo)->is_eating = 0;
        handle_message(philo, SLEEPING, KMAG);
        usleep(TO_MICRO(((t_philo *)philo)->rules->time_to_sleep));
        handle_message(philo, THINKING, KCYN);
    }
    return NULL;
}
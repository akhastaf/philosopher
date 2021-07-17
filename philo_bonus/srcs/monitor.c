/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:35:37 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/17 20:56:43 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int    check_death(t_philo *philo)
{
    size_t  cur_time;

    if (philo->eated_meals >= philo->rules->meals && philo->rules->meals != -1)
    {
        sem_wait(philo->display);
        exit(0);
    }
    if (!philo->is_eating)
    {
        sem_wait(philo->eating);
        cur_time = get_time();
        if (cur_time - philo->last_time_eat >= philo->rules->time_to_die)
            return (1);
        sem_post(philo->eating);
    }
    return (0);
} 

void    *monitor(void*  philo)
{
    while (1)
    {
        if (check_death(philo))
        {
            sem_wait(((t_philo *)philo)->display);
            ft_putstr_fd(KRED, 1);
            ft_putnbr_fd(ft_get_time(philo), 1);
            write(1, " ", 1);
            ft_putnbr_fd(((t_philo *)philo)->index, 1);
            ft_putstr_fd(DIED, 1);
            kill(((t_philo *)philo)->id, SIGINT);
            return (NULL);
        }
        usleep(1e3);
    }
    return (NULL);
}
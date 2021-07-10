/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:26:23 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/10 13:04:21 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static unsigned long int    ft_get_time(t_philo *philo)
{
    struct timeval tv;
    unsigned long int usec;
    
    gettimeofday(&tv, NULL);
    usec = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - philo->rules->time;
    return (usec);
}
void    handle_message(t_philo *philo, char *message, char *color)
{
    (void)color;
    (void)message;
    pthread_mutex_lock(philo->display);
    ft_putstr_fd(color, 1);
    ft_putnbr_fd(ft_get_time(philo), 1);
    write(1, " ", 1);
    ft_putnbr_fd(philo->index, 1);
    ft_putendl_fd(message, 1);
    ft_putstr_fd(KNRM, 1);
    pthread_mutex_unlock(philo->display);
}
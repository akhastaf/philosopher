/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:21:03 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/15 10:30:27 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

unsigned long int	ft_get_time(t_philo *philo)
{
	struct timeval		tv;
	unsigned long int	usec;

	gettimeofday(&tv, NULL);
	usec = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - philo->rules->time;
	return (usec);
}

void	handle_message(t_philo *philo, char *message, char *color)
{
	sem_wait(philo->display);
	ft_putstr_fd(color, 1);
	ft_putnbr_fd(ft_get_time(philo), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->index, 1);
	ft_putendl_fd(message, 1);
	ft_putstr_fd(KNRM, 1);
	sem_post(philo->display);
}

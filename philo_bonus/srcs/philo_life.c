/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:14:29 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/18 12:21:21 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	eat(t_philo *philo)
{
	handle_message(philo, EATING, KGRN);
	sem_wait(philo->eating);
	philo->is_eating = 1;
	philo->last_time_eat = get_time();
	ft_usleep(philo->rules->time_to_eat);
	sem_post(philo->eating);
	philo->eated_meals++;
	philo->is_eating = 0;
}

void	philo_life(t_philo *philo)
{
	if (philo->index % 2 == 0)
		usleep(100);
	while (1)
	{
		sem_wait(philo->forks);
		handle_message(philo, TAKE_FORK, KBLU);
		sem_wait(philo->forks);
		handle_message(philo, TAKE_FORK, KBLU);
		eat(philo);
		sem_post(philo->forks);
		sem_post(philo->forks);
		handle_message(philo, SLEEPING, KMAG);
		ft_usleep(philo->rules->time_to_sleep);
		handle_message(philo, THINKING, KCYN);
	}
}

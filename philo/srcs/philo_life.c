/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:55:29 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/15 11:57:15 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	get_left_right(t_philo *philo, int *left, int *right)
{
	*left = philo->index - 1;
	if (philo->index == philo->rules->number_philos)
		*right = 0;
	else
		*right = philo->index;
}

void	eat(t_philo *philo)
{
	handle_message(philo, EATING, KGRN);
	pthread_mutex_lock(&philo->eating);
	philo->is_eating = 1;
	philo->last_time_eat = get_time();
	ft_usleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(&philo->eating);
	philo->eated_meals++;
	philo->is_eating = 0;
}

void	*philo_life(void *philo)
{
	int	left;
	int	right;

	if (((t_philo *)philo)->index % 2 == 0)
		usleep(200);
	while (1)
	{
		get_left_right(philo, &left, &right);
		pthread_mutex_lock(&((t_philo *)philo)->forks[left]);
		handle_message(philo, TAKE_FORK, KBLU);
		pthread_mutex_lock(&((t_philo *)philo)->forks[right]);
		handle_message(philo, TAKE_FORK, KBLU);
		eat(philo);
		pthread_mutex_unlock(&((t_philo *)philo)->forks[left]);
		pthread_mutex_unlock(&((t_philo *)philo)->forks[right]);
		handle_message(philo, SLEEPING, KMAG);
		ft_usleep(((t_philo *)philo)->rules->time_to_sleep);
		handle_message(philo, THINKING, KCYN);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:58:21 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/18 12:10:47 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_death(t_info *info)
{
	size_t			cur_time;
	unsigned int	i;

	i = -1;
	while (++i < info->rules->number_philos)
	{
		if (!info->philos[i].is_eating)
		{
			pthread_mutex_lock(&info->philos[i].eating);
			cur_time = get_time();
			if (cur_time - info->philos[i].last_time_eat
				>= info->rules->time_to_die)
			{
				pthread_mutex_lock(info->philos[i].display);
				ft_putstr_fd(KRED, 1);
				ft_putnbr_fd(ft_get_time(&info->philos[i]), 1);
				write(1, " ", 1);
				ft_putnbr_fd(info->philos[i].index, 1);
				ft_putendl_fd(DIED, 1);
				return (1);
			}
			pthread_mutex_unlock(&info->philos[i].eating);
		}
	}
	return (0);
}

int	check_finish(t_info *info)
{
	unsigned int	i;
	unsigned int	r;

	i = 0;
	r = 0;
	while (i < info->rules->number_philos)
	{
		if (info->philos[i].eated_meals >= info->rules->meals)
			r++;
		i++;
	}
	if (r != info->rules->number_philos)
		r = 0;
	return (r);
}

void	*supervisor(void *info)
{
	unsigned int	i;

	i = 0;
	while (i < ((t_info *)info)->rules->number_philos)
	{
		pthread_create(&(((t_info *)info)->philos[i].id), NULL,
			philo_life, (void *)&(((t_info *)info)->philos[i]));
		i++;
	}
	usleep(100);
	while (1)
	{
		if (check_death(info))
			return (NULL);
		if (((t_info *)info)->rules->meals != -1 && check_finish(info))
		{
			pthread_mutex_lock(&((t_info *)info)->display);
			ft_putstr_fd("all philospher is eaten at least ", 1);
			ft_putnbr_fd(((t_info *)info)->rules->meals, 1);
			ft_putendl_fd(" times", 1);
			return (NULL);
		}
	}
	return (NULL);
}

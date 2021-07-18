/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:33:09 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/18 12:40:08 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_wait(t_info *info)
{
	unsigned int	i;
	int				status;

	i = -1;
	while (++i < info->rules->number_philos)
	{
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		if (!status)
			sem_post(info->display);
	}
	i = -1;
	while (++i < info->rules->number_philos)
		kill(info->philos[i].id, SIGILL);
}

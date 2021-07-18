/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:20:15 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/18 12:38:04 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	check_args(t_info *info, int ac, char **av)
{
	info->rules = malloc(sizeof(t_info));
	info->rules->number_philos = ft_atoi(av[1]);
	if (!info->rules->number_philos || !check_digits(ac, av))
	{
		ft_puterror("Arguments error\n");
		return (1);
	}
	info->philos = malloc(sizeof(t_philo) * info->rules->number_philos);
	if (!info->philos)
	{
		ft_puterror("Fatal error\n");
		return (1);
	}
	init_data(info, ac, av);
	return (0);
}

void	init_data(t_info *info, int ac, char **av)
{
	unsigned int	i;

	sem_unlink("/philo_forks");
	info->forks = sem_open("/philo_forks", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR,
			info->rules->number_philos);
	info->rules->time_to_die = ft_atoi(av[2]);
	info->rules->time_to_eat = ft_atoi(av[3]);
	info->rules->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->rules->meals = ft_atoi(av[5]);
	else
		info->rules->meals = -1;
	i = 0;
	while (i < info->rules->number_philos)
	{
		info->philos[i].index = i + 1;
		info->philos[i].eated_meals = 0;
		info->philos[i].is_eating = 0;
		info->philos[i].rules = info->rules;
		info->philos[i].display = info->display;
		info->philos[i].forks = info->forks;
		info->philos[i].last_time_eat = get_time();
		i++;
	}	
}

int	init_philos(t_info *info)
{
	unsigned int	i;

	i = -1;
	while (++i < info->rules->number_philos)
	{
		info->philos[i].id = fork();
		if (!info->philos[i].id)
		{
			if (info->philos[i].index % 2 == 0)
				usleep(100);
			sem_unlink("/philo_eating");
			info->philos[i].eating = sem_open("/philo_eating", O_CREAT | O_EXCL,
					S_IRUSR | S_IWUSR, 1);
			pthread_create(&info->philos[i].monitor, NULL, monitor,
				&info->philos[i]);
			philo_life(&info->philos[i]);
			exit(0);
		}
	}
	ft_wait(info);
	sem_wait(info->display);
	ft_putstr_fd("all philospher is eaten at least ", 1);
	ft_putnbr_fd(info->rules->meals, 1);
	ft_putendl_fd(" times", 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_info			info;
	struct timeval	tv;

	if (ac < 5 || ac > 6)
	{
		write(2, "Error : missing arguments\n", 26);
		return (1);
	}
	sem_unlink("/philo_print");
	info.display = sem_open("/philo_print", O_CREAT | O_EXCL,
			S_IRUSR | S_IWUSR, 1);
	if (check_args(&info, ac, av))
		return (1);
	gettimeofday(&tv, NULL);
	info.rules->time = (tv.tv_sec * 1e3) + (tv.tv_usec / 1e3);
	if (init_philos(&info))
		return (1);
	sem_close(info.display);
	sem_close(info.forks);
	return (0);
}

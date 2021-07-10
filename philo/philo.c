/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:46:39 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/10 17:50:46 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int    init_args(t_info *info, int ac, char **av)
{
    unsigned int i;
    
    info->rules = malloc(sizeof(t_info));
    info->rules->number_philos = ft_atoi(av[1]);
    if (!info->rules->number_philos)
    {
        ft_puterror("Arguments error\n");
        return (1);
    }
    info->philos =  malloc(sizeof(t_philo) * info->rules->number_philos);
    if (!info->philos)
    {
        ft_puterror("Fatal error\n");
        return (1);
    }
    info->forks =  malloc(sizeof(pthread_mutex_t) * info->rules->number_philos);
    if (!info->forks)
    {
        ft_puterror("Fatal error\n");
        return (1);
    }
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
        (info->philos[i]).forks = info->forks;
        (info->philos[i]).rules = info->rules;
        info->philos[i].eated_meals = 0;
        info->philos[i].is_eating = 0;
        (info->philos[i]).display = &(info->display);
        pthread_mutex_init(&(info->philos[i].eating), NULL);
        i++;
    }
    return (0);
}

int     init_philos(t_info *info)
{
    unsigned int i;

    i = 0;
    pthread_mutex_init(&(info->display), NULL);
    while (i < info->rules->number_philos)
    {
        pthread_mutex_init(&(info->forks[i]), NULL);
        i++;
    }
    pthread_create(&info->supervisor, NULL, supervisor, info);
    pthread_join(info->supervisor, NULL);
    return (0);
}

int     main(int ac, char **av)
{
    t_info info;
    struct timeval tv;
    
    if (ac < 5 || ac > 6)
    {
        write(2, "Error : missing arguments\n", 26);
        return (1);
    }
    if (init_args(&info, ac, av))
        return (1);
    gettimeofday(&tv, NULL);
    info.rules->time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    // printf("%ld \n", get_time_pass(info.rules->time));
    // ft_usleep(TO_MICRO(300));
    //printf("%ld \n", get_time_pass(info.rules->time));
    if (init_philos(&info))
        return (1);
    return (0);
}
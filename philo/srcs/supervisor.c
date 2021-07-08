/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:58:21 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/08 18:23:46 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
// int     check_death(t_info *info)
// {
//     return (0);
// }

int     check_finish(t_info *info)
{
    unsigned int i;
    unsigned int r;

    i = 0;
    r = 0;
    while (i < info->rules->number_philos)
    {
        if (info->philos[i].eated_meals == info->rules->meals)
            r++;
        i++;
    }
    if (r == info->rules->number_philos)
        r = 0;
    return r;
}

void    *supervisor(void *info)
{
    unsigned int i;
    
    i = 0;
    while (i < ((t_info *)info)->rules->number_philos)
    {
        pthread_create(&(((t_info *)info)->philos[i].id), NULL, philo_life, (void *)&(((t_info *)info)->philos[i]));
        i++;
    }
    while (1)
    {
        // if (check_death(info))
        //     return (NULL);
        if (check_finish(info))
            return (NULL);
        usleep(10);
    }
}
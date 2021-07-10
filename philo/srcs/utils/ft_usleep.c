/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:28:43 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/10 14:50:46 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_usleep(size_t time) // micro
{
    size_t cur_time, cur_time_0;
    unsigned long long time_2;
    cur_time_0 = uget_time();
    time_2 = time  - 10000;
    usleep(time_2);
    time_2 = 10000;
    
    cur_time = uget_time();
    while (uget_time() - cur_time < time_2)
    {
        //time_2 = time_2 - (uget_time() - cur_time);
        //printf("%lld\n", time_2);
        // if (get_time() - cur_time >= time)
        //     return ;
        //usleep(1e3);
    }
    ft_putnbr_fd(uget_time() - cur_time_0, 1);
}
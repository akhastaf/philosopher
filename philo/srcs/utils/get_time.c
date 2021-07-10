/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:33:43 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/10 10:59:35 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

size_t  get_time()
{
    struct timeval tv;
    size_t usec;

    gettimeofday(&tv, NULL);
    usec = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    return (usec);
}

size_t  uget_time()
{
    struct timeval tv;
    size_t usec;

    gettimeofday(&tv, NULL);
    usec = ((tv.tv_sec * 1e6) + tv.tv_usec);
    return (usec);
}

size_t  get_time_pass(size_t t0)
{
    size_t usec;

    usec = get_time() - t0;
    return (usec);
}
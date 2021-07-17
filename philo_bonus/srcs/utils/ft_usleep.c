/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:28:43 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/14 19:09:33 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	usleep((time * 1e3) - 20000);
	while (get_time() - start < time)
		;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:46:04 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/18 12:15:35 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_digits(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_str_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

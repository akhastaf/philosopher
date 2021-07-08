/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:32:59 by akhastaf          #+#    #+#             */
/*   Updated: 2021/07/06 18:29:02 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = -n;
	}
	if (nbr <= 9)
	{
		c = '0' + nbr;
		write(fd, &c, 1);
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		c = nbr % 10 + '0';
		write(fd, &c, 1);
	}
}
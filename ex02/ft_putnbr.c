/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:34:07 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/15 08:07:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(unsigned int nb)
{
	char	c;

	if (nb == 0)
		return ;
	print_num(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (!nb)
		write(1, "0", 1);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	print_num(nb);
}

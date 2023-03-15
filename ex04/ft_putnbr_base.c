/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:02:47 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/15 20:06:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_base_unsigned_num(unsigned int nbr, unsigned int base,
		char *replace)
{
	if (!nbr)
		return ;
	print_base_unsigned_num(nbr / base, base, replace);
	write(1, replace + nbr % base, 1);
}

int	ft_strlduplicate(char *str)
{
	unsigned int	i;
	char			*_str;

	i = 0;
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (0);
		_str = str;
		while (*_str++)
			if (*str == *_str)
				return (0);
		str++;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;

	base_length = ft_strlduplicate(base);
	if (base_length <= 1)
		return ;
	if (!nbr)
		write(1, base, 1);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	print_base_unsigned_num(nbr, base_length, base);
}

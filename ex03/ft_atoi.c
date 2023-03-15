/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:25:18 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/15 20:33:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sgin;
	int	result;

	sgin = 1;
	result = 0;
	while ((0x08 < *str && *str < 0x0e) || *str == 0x20)
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sgin *= -1;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (sgin * result);
}

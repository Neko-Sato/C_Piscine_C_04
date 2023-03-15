/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:05:15 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/15 20:18:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	str_index(char c, char *str)
{
	char	*_str;

	_str = str;
	while (*str)
		if (*(str++) == c)
			return (str - _str);
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sgin;
	int	result;
	int	base_length;
	int	temp;

	sgin = 1;
	result = 0;
	base_length = ft_strlduplicate(base);
	if (base_length <= 1)
		return (0);
	while ((0x08 < *str && *str < 0x0e) || *str == 0x20)
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sgin *= -1;
	while (*str)
	{
		temp = str_index(*str, base) - 1;
		if (temp < 0)
			return (0);
		result *= base_length;
		result += temp;
		str++;
	}
	return (sgin * result);
}

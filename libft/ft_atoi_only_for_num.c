/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_only_for_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <cmero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:24:10 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:24:11 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	positive_or_negative(char in, int sign)
{
	if (in == 45)
		sign = -sign;
	return (sign);
}

int	ft_atoi_only_for_num(const char *str)
{
	int		in;
	int		sign;
	long	num;

	in = 0;
	sign = 1;
	num = 0;
	while ((((str[in] > 8) && (str[in] < 14)) || str[in] == 32) && \
			str[in] != '\0')
		in++;
	if (str[in] == 43 || str[in] == 45)
		sign = positive_or_negative(str[in++], sign);
	while (str[in])
	{
		if (str[in] < 48 || str[in] > 57)
			ft_error("Error: not number in the sump");
		num = num * 10 + (str[in] - '0');
		in++;
	}
	num = num * sign;
	if (num > 2147483647 || num < -2147483648)
		ft_error("Error: argument not in INT");
	return (num);
}

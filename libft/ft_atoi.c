/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:58:03 by zyunusov          #+#    #+#             */
/*   Updated: 2021/11/29 16:21:37 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long int	num;
	long int	old_num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		old_num = num;
		num = (num * 10) + (*str - '0');
		if ((old_num < 0 && num > 0) || (old_num > 0 && num < 0))
			return ((sign == 1) * -1);
		str++;
	}
	return (num * sign);
}

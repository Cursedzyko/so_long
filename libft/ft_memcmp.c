/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:19:57 by zyunusov          #+#    #+#             */
/*   Updated: 2021/11/23 14:52:00 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*l1;
	unsigned char	*l2;

	l1 = (unsigned char *)s1;
	l2 = (unsigned char *)s2;
	while (n--)
	{
		if (*l1 != *l2)
			return (*l1 - *l2);
		l1++;
		l2++;
	}
	return (0);
}

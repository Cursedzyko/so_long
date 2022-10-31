/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:00:44 by zyunusov          #+#    #+#             */
/*   Updated: 2021/11/24 21:23:22 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ch;

	ch = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ch[i] == ((unsigned char )c))
			return (ch + i);
		i++;
	}
	return (NULL);
}

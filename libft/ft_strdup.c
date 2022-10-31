/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:51:56 by zyunusov          #+#    #+#             */
/*   Updated: 2021/11/23 14:56:38 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	i;

	c = (char *)malloc(sizeof(*c) * (ft_strlen(s) + 1));
	if (c == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s[i])
		{
			c[i] = s[i];
			i++;
		}
		c[i] = '\0';
		return (c);
	}
}

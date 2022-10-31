/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:00:23 by zyunusov          #+#    #+#             */
/*   Updated: 2021/12/04 13:23:09 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dstlen(char *dst, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	char const	*s;
	size_t		dst_size;
	size_t		dst_len;

	d = dst;
	s = src;
	dst_len = ft_dstlen(dst, size);
	d = dst + dst_len;
	dst_size = size - dst_len;
	if (dst_size == 0)
		return (dst_len + ft_strlen(s));
	while (*s != '\0')
	{
		if (dst_size != 1)
		{
			*d = *s;
			d++;
			dst_size--;
		}
		s++;
	}
	*d = '\0';
	return (dst_len + (s - src));
}

static size_t	ft_dstlen(char *dst, size_t size)
{
	char	*d;
	size_t	len;

	d = dst;
	while (size != 0 && *d != '\0')
	{
		d++;
		size--;
	}
	len = d - dst;
	return (len);
}

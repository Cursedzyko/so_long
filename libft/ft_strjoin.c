/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:29 by zyunusov          #+#    #+#             */
/*   Updated: 2022/10/28 19:13:31 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (ft_strdup(""));
		if (!s1)
			return (ft_strdup(s2));
		return (ft_strdup(s1));
	}
	i = -1;
	j = -1;
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (0);
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[++j])
		if (s2[j] != 13)
			newstr[i++] = s2[j];
	newstr[i] = '\0';
	return (newstr);
}

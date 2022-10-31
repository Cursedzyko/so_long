/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:31:26 by bkeklik           #+#    #+#             */
/*   Updated: 2022/10/28 19:06:43 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen1(const char *str);
char	*ft_join(char *str, char *buff);
char	*ft_strchr(const char *str, int c);
char	*ft_line(char *str);
char	*ft_str(char *str);
char	*ft_read_buff(int fd, char *str);
char	*get_next_line(int fd);

#endif
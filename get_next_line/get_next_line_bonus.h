/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:44:33 by darotche          #+#    #+#             */
/*   Updated: 2023/08/11 02:52:50 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3955
# endif

# define OPEN_MAX 4096

char	*get_next_line(int fd);
char	*ft_strchr(const char *line, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const	*s, char c);
char	*ft_read(int fd, char *stash);
char	*ft_newline(char *stash);
char	*ft_newstash(char *stash);
int		ft_strcount(char const *s, char c);
size_t	ft_strlen(const char	*str);

#endif
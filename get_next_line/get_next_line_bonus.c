/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:32:57 by darotche          #+#    #+#             */
/*   Updated: 2023/08/11 02:52:44 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		*stash[OPEN_MAX];
	char			*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char));
		stash[fd][0] = '\0';
	}
	stash[fd] = ft_read(fd, stash[fd]);
	if (!stash[fd])
	{
		free (stash[fd]);
		return (NULL);
	}
	newline = ft_newline(stash[fd]);
	stash[fd] = ft_newstash(stash[fd]);
	return (newline);
}

char	*ft_read(int fd, char *stash)
{
	char	*line;
	int		bytes_read;

	bytes_read = 1;
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (ft_strchr(stash, '\n') == 0 && bytes_read > 0)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			free(line);
			return (NULL);
		}
		line[bytes_read] = '\0';
		stash = ft_strjoin(stash, line);
	}
	free (line);
	return (stash);
}

char	*ft_newline(char *stash)
{
	char	*nl;
	int		line_len;

	line_len = 0;
	if (stash[line_len] == '\0')
		return (NULL);
	while (stash[line_len] && stash[line_len] != '\n')
		line_len++;
	nl = malloc(sizeof(char) * line_len + 2);
	if (!nl)
		return (NULL);
	line_len = 0;
	while (stash[line_len] && stash[line_len] != '\n')
	{
		nl[line_len] = stash[line_len];
		line_len++;
	}
	if (stash[line_len] == '\n')
	{
		nl[line_len] = stash[line_len];
		line_len++;
	}
	nl[line_len] = '\0';
	return (nl);
}

char	*ft_newstash(char *stash)
{
	char	*newstash;
	int		pos;
	int		i;

	pos = 0;
	while (stash[pos] && stash[pos] != '\n')
		pos++;
	if (stash[pos] == '\0')
		return (free(stash), NULL);
	newstash = malloc(sizeof(char) * (ft_strlen(stash) - (pos)));
	if (!newstash)
		return (NULL);
	pos++;
	i = 0;
	while (stash[pos])
	{
		newstash[i] = stash[pos];
		i++;
		pos++;
	}
	newstash[i] = '\0';
	free (stash);
	return (newstash);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	fd = open("./text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }

///MAIN DAI
// int main()
// {
// 	int fd;
// 	int i = 0;
// 	fd = open("text.txt", O_RDONLY);

// 	while (i < 8)
// 	{
// 		get_next_line(fd);
// 		printf("\033[0;32m|||||||||||| %d LOOOOOP|||||||\n\033[0m",i);	
// 		i++;
// 	}
// 	return 0;
// }
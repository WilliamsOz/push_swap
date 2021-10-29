/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 14:43:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 12:43:47 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char	*get_second(char *buffer, char *line, int len, int i)
{
	char	*final_str;

	len = ft_strlen(line) + 2;
	final_str = (char *)malloc(sizeof(char) * len);
	while (line[i] != '\0')
	{
		final_str[i] = line[i];
		i++;
	}
	final_str[i] = buffer[0];
	final_str[i + 1] = '\0';
	free(line);
	line = final_str;
	return (line);
}

static char	*get_first(char *buffer, char *line)
{
	line = (char *)malloc(sizeof(char) * 2);
	line[0] = buffer[0];
	line[1] = '\0';
	return (line);
}

int	get_next_line(int fd, char **line)
{
	int		count;
	char	buffer[1];
	int		eof;

	if (!line || fd < 0 || read(fd, NULL, 0))
		return (-1);
	eof = read(fd, buffer, 1);
	count = 0;
	while (eof > 0 && buffer[0] != '\n')
	{
		if (count == 0 && eof > 0)
		{
			*line = get_first(buffer, *line);
			count++;
		}
		else if (eof > 0 && buffer[0] != '\n')
			*line = get_second(buffer, *line, 0, 0);
		eof = read(fd, buffer, 1);
	}
	return (eof);
}

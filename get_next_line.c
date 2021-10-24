/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconceic <tconceic@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:20:11 by tconceic          #+#    #+#             */
/*   Updated: 2021/10/24 15:13:01 by tconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/***Função que guarda o que sobra do buffersize***/
static char	make_backup(char *str)
{
	int		i;
	char	backup;

	i = 0;
	while (str[i] && str[i] != '\0' && str[i] != '\n')
		i++;
	backup = (char *)malloc(sizeof (char) * ft_strlen(str) - i + 1));
	if (!backup)
		return (NULL);
	ft_strlcpy(backup, str, ft_strlen(str) - i + 1);
	return (backup);
}

/*Retorna a string qdo tem '\n'*/
static char	*find_break_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] || str[i] != '\0' || str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof (char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, (i + 2));
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* Função que lê e agrupa as strings caso precise*/
static char	*read_and_join(int fd, char *str, void *buffer)
{
	int		read_buffer;
	int		cntrl;
	char	*temp;

	read_buffer = 1;
	cntrl = 0;
	while (cntrl == 0 || read_buffer != 0)
	{
		read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1 )
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_buffer] = '\0';
		if (!str)
			str = ft_strdup("");
		temp = str;
		str = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(str, '\n'))
			cntrl = 1;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char		*buffer;

	line = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (buffer == '\0')
	{
		free(buffer);
		return (NULL);
	}
	str = read_and_join(fd, str, buffer);
	if (!str)
		return (NULL);
	line = find_break_line(str);
	str = make_backup(str);
	return (line);
}

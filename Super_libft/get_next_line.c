/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:48:24 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 13:19:34 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

char	*ft_free_and_null(char *res, char *buffer)
{
	free(res);
	free(buffer);
	return (NULL);
}

char	*ft_read(int fd, char *buffer)
{
	char	*res;
	int		byte_read;

	res = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (res == NULL)
		return (free(buffer), NULL);
	byte_read = 1;
	if (!buffer)
	{
		buffer = malloc(1);
		if (buffer)
			buffer[0] = '\0';
	}
	while (buffer && !ft_strchr(buffer, '\n') && byte_read != 0)
	{
		byte_read = read (fd, res, BUFFER_SIZE);
		if (byte_read == -1)
			return (ft_free_and_null(res, buffer));
		res[byte_read] = '\0';
		buffer = ft_strjoin_next_line(buffer, res);
	}
	free (res);
	if (!buffer || buffer[0] == '\0')
		return (ft_free_and_null(NULL, buffer));
	return (buffer);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = malloc(sizeof (char) * (i + 2));
	else
		line = malloc(sizeof (char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean(char *buffer, char *line)
{
	int		i;
	char	*new_buffer;
	int		len;
	int		j;

	j = 0;
	i = ft_strlen(line);
	len = ft_strlen(buffer) - ft_strlen(line);
	if (len == 0)
	{
		free (buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof (char) * (len + 1));
	if (new_buffer == NULL)
		return (free(buffer), NULL);
	while (buffer[i])
	{
		new_buffer[j] = buffer[i];
		i++;
		j++;
	}
	new_buffer[j] = '\0';
	free (buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_clean(buffer, line);
	return (line);
}

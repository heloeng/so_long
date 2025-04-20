/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:51:42 by helde-so          #+#    #+#             */
/*   Updated: 2024/12/30 14:09:40 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*new_buf;
	size_t	len;

	if (!buffer || !*buffer)
		return (NULL);
	if (ft_strchr(*buffer, '\n'))
	{
		len = ft_strchr(*buffer, '\n') - *buffer + 1;
		line = ft_substr(*buffer, 0, len);
		if (!line)
			return (free_buffer(buffer, &line));
		new_buf = ft_strdup(*buffer + len);
		if (!new_buf)
			return (free_buffer(buffer, &line));
		free_buffer(buffer, NULL);
		*buffer = new_buf;
		return (line);
	}
	line = ft_strdup(*buffer);
	if (!line)
		return (free_buffer(buffer, NULL));
	free_buffer(buffer, NULL);
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
	char	*temp;
	char	*read_buf;
	ssize_t	bytes_read;

	bytes_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	read_buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_buffer(&buffer, &read_buf));
		read_buf[bytes_read] = '\0';
		temp = ft_strjoin(buffer, read_buf);
		free_buffer(&buffer, NULL);
		buffer = temp;
	}
	free_buffer(&read_buf, NULL);
	if ((buffer[0] == '\0' || !buffer) && bytes_read == 0)
		return (free_buffer(&buffer, NULL));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	if (!line)
		return (free_buffer(&buffer, NULL));
	return (line);
}

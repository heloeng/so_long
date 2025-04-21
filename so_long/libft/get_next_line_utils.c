/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:51:21 by helde-so          #+#    #+#             */
/*   Updated: 2024/12/30 13:55:01 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buffer;
	size_t	index;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	buffer = (char *)malloc(len_s1 + len_s2 + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (*s1)
		buffer[index++] = *s1++;
	while (*s2)
		buffer[index++] = *s2++;
	buffer[len_s1 + len_s2] = '\0';
	return (buffer);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb > ((size_t)-1) / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((unsigned char *)ptr)[i++] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(&s[str_len]));
	if (len > (str_len - start))
		len = str_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = start;
	j = 0;
	while (i < str_len && j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}

char	*free_buffer(char **buf1, char **buf2)
{
	if (buf1 && *buf1)
	{
		free(*buf1);
		*buf1 = NULL;
	}
	if (buf2 && *buf2)
	{
		free(*buf2);
		*buf2 = NULL;
	}
	return (NULL);
}

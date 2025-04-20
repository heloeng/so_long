
#include "libft.h"

size_t	ft_line_length(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

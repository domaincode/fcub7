#include "parsing.h"

char	*ft_strdup(char	*str)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = (char *)malloc(ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char	*string;

	string = (char *)malloc((ft_strlen(str) + ft_strlen(buffer)) + 1);
	if (!string)
		return (NULL);
	ft_joinstring(string, str, buffer);
	return (string);
}

void	ft_joinstring(char *string, char *str, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		string[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		string[i + j] = buffer[j];
		j++;
	}
	string[j + i] = '\0';
}

char	*ft_substr(char *string, int start, int len)
{
	int		i;
	int		j;
	char	*line;

	if (!string)
		return (NULL);
	i = 0;
	j = ft_strlen(string);
	if (j < start)
		return (ft_strdup(""));
	if (len > j - start)
		len = j - start;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	while (len > i)
	{
		line[i] = string[start + i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

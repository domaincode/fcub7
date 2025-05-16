#include "parsing.h"

char	*ft_strchr(char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (s == NULL)
	{
		return (NULL);
	}
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_readfile(int fd, char *string, char *buffer)
{
	char	*tmp;
	int		bufferread;

	bufferread = 1;
	while (bufferread > 0)
	{
		bufferread = read(fd, buffer, BUFFER_SIZE);
		if (bufferread == -1)
		{
			free(string);
			return (NULL);
		}
		if (bufferread == 0)
			break ;
		buffer[bufferread] = '\0';
		if (!string)
			string = ft_strdup("");
		tmp = string;
		string = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (string);
}

char	*ft_freeline(char *string)
{
	char	*line;
	int		i;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\0' || string[1] == '\0')
		return (NULL);
	line = ft_substr(string, i + 1, ft_strlen(string) - i);
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
	string[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*string;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(string);
		free(buffer);
		buffer = NULL;
		string = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = ft_readfile(fd, string, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	string = ft_freeline(line);
	return (line);
}

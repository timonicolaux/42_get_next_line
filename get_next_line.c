/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:59:41 by tnicolau          #+#    #+#             */
/*   Updated: 2023/12/13 14:33:03 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*error_management(char *str)
{
	free(str);
	return (NULL);
}

char	*extract_line(char	*temp)
{
	int		i;
	char	*str;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (temp[++i] && temp[i] != '\n')
		str[i] = temp[i];
	if (temp[i] == '\n')
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*update_temp(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
		return (error_management(temp));
	str = malloc(sizeof(char) * ((ft_strlen(temp) - i) + 1));
	if (!str)
		return (error_management(temp));
	i++;
	while (temp[i])
		str[j++] = temp[i++];
	str[j] = '\0';
	free(temp);
	return (str);
}

char	*store_buffer(int fd, char *temp)
{
	char	*buffer;
	int		buffer_result;

	buffer_result = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (error_management(temp));
	while (!ft_strchr(temp, '\n') && buffer_result)
	{
		buffer_result = read(fd, buffer, BUFFER_SIZE);
		if (buffer_result == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[buffer_result] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	int			i;
	static char	store[BUFFER_SIZE + 1];

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_strdup(store);
	if (!temp)
		return (NULL);
	while (i < (BUFFER_SIZE + 1))
		store[i++] = '\0';
	temp = store_buffer(fd, temp);
	if (!temp)
		return (NULL);
	line = extract_line(temp);
	temp = update_temp(temp);
	if (ft_strlen(temp))
		ft_memmove(store, temp, ft_strlen(temp));
	else
		store[0] = '\0';
	free(temp);
	return (line);
}

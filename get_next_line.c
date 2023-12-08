/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:59:41 by tnicolau          #+#    #+#             */
/*   Updated: 2023/12/08 16:05:40 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_buffer_left(char *temp, int j)
{
	int		length;
	char	*str;

	length = 0;
	str = NULL;
	if (!temp)
		return (NULL);
	while (temp[j])
	{
		j++;
		length++;
	}
	j -= length;
	// printf("substr\n");
	str = ft_substr(temp, j, length);
	free(temp);
	//if str == NULL free buffer
	return (str);
}

char	*extract_line(char *temp, char **temp_adress)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = NULL;
	// printf("extract line\n");
	if (!temp)
		return (error_management(temp));
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			result = ft_calloc(sizeof(char), (i + 2));
			if (!result)
				return (NULL);
			while (j < (i + 1))
			{
				result[j] = temp[j];
				j++;
			}
			if (result[i] == '\n')
				result[i + 1] = '\0';
			*temp_adress = save_buffer_left(temp, j);
			return (result);
		}
		i++;
	}
	return (result);
}
char	*print_nolinebreak(char *temp)
{
	char	*result;
	int		size;
	int		i;

	i = 0;
	// printf("print nolb\n");
	if (!temp)
		return (NULL);
	size = ft_strlen(temp);
	result = ft_calloc(sizeof(char), (size + 1));
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = temp[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	check_lb(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*create_temp(char *buffer)
{
	char	*str;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(buffer);
	str = ft_calloc(sizeof(char), length + 1);
	if (!str)
		return (NULL);
	while (buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	int			buffer_length;
	int			marker;
	char		*buffer;
	static char	*temp;
	char		*result;

	result = NULL;
	buffer = NULL;
	marker = 1;
	if (!BUFFER_SIZE || !fd)
		return (0);
	while (marker == 1)
	{
		printf("temp: %s\n", temp);
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		buffer_length = read(fd, buffer, BUFFER_SIZE);
		if (buffer_length == -1)
			return (error_management(buffer));
		// if (buffer_length == 0)
		// 	return (error_management(buffer));
		if (buffer_length > 0)
			buffer[buffer_length] = '\0';
		if (!temp && buffer_length > 0)
			temp = create_temp(buffer);
		//here does not free ?
		if (buffer_length == 0 && temp && !check_lb(temp))
		{
			free(buffer);
			result = print_nolinebreak(temp);
			temp = NULL;
			return (result);
		}
		// if (!temp)
		// 	break;
		if (!ft_strncmp(temp, buffer) && buffer_length)
			temp = ft_strjoin(temp, buffer, buffer_length);
		if (temp)
		{
			free(buffer);
			result = extract_line(temp, &temp);
		}
		if (result != NULL || buffer_length == 0)
			marker = 0;
	}
	// printf("bufferfinal: %s\n", buffer);
	// free(buffer);
	return (result);
}
int	main(void)
{
	int	num;
	int	i = 0;
	char	*result;

	num = open("../test3.txt", O_RDONLY);
	// if (num <= 0)
	// 	close(num);
	while (i < 4)
	{
		result = get_next_line(num);
		printf("result : %s", result);
		free(result);
		i++;
	}
	close(num);
}

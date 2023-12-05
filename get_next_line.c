/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:59:41 by tnicolau          #+#    #+#             */
/*   Updated: 2023/12/05 14:57:26 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_buffer_left(char *temp, int j)
{
	int		length;
	char	*str;

	length = 0;
	str = NULL;
	if (temp[j])
	{
		while (temp[j])
		{
			j++;
			length++;
		}
		j -= length;
		// printf("len: %d\n", length);
		str = ft_substr(temp, j, length);
	}
	free(temp);
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
	if (!temp)
		return (error_management(temp));
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			result = ft_calloc(sizeof(char), (i + 1));
			if (!result)
				return (NULL);
			while (j < i)
			{
				result[j] = temp[j];
				j++;
			}
			result[j] = '\0';
			*temp_adress = save_buffer_left(temp, (j + 1));
		}
		i++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	int			buffer_length;
	int			marker;
	char		*buffer;
	static char	*temp;
	char		*result;

	result = NULL;
	marker = 1;
	if (!BUFFER_SIZE || !fd)
		return (0);
	result = extract_line(temp, &temp);
	if (result)
		return (result);
	while (marker == 1)
	{
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		buffer_length = read(fd, buffer, BUFFER_SIZE);
		if (buffer_length == -1)
			return (error_management(buffer));
		if (!temp && buffer_length)
			temp = buffer;
		if (!temp)
			break;
		// printf("temp: %s\n", temp);
		// printf("buffer: %s\n", buffer);
		if (temp != buffer && buffer_length)
			temp = ft_strjoin(temp, buffer);
		// printf("temp2: %s\n", temp);
		result = extract_line(temp, &temp);
		if (result != NULL || buffer_length == 0)
			marker = 0;
	}
	free(buffer);
	// free(temp);
	return (result);
}
int	main(void)
{
	int	num;
	int	i = 0;
	char	*result;

	num = open("test.txt", O_RDONLY);
	// if (num <= 0)
	// 	close(num);
	while (i < 5)
	{
		result = get_next_line(num);
		printf("result : %s\n", result);
		free(result);
		i++;
	}
	close(num);
}

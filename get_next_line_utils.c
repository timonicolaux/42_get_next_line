/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:14:35 by tnicolau          #+#    #+#             */
/*   Updated: 2023/12/08 15:00:16 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(int nmemb, int size)
{
	char	*res;

	if (!nmemb || !size)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}

void	ft_bzero(char *s, int n)
{
	char	*str;
	int			i;

	if (s)
	{
		str = (char *)s;
		i = 0;
		while (i < n)
		{
			str[i] = 0;
			i++;
	}
	}
}

int	ft_strncmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2, int buffer_length)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	// printf("join\n");
	i = 0;
	j = 0;
	if ((ft_strlen(s1) == ft_strlen(s2)) && buffer_length > 1)
		return (s1);
	if (s1)
		size = ft_strlen(s1) + ft_strlen(s2);
	else
		size = ft_strlen(s2);
	str = ft_calloc(sizeof(char), (size + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	// printf("size: %d\n", size);
	str[i] = '\0';
	// free(s2);
	free(s1);
	return (str);
}

char	*error_management(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;
	int		length;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start + len > length)
		len = length - start;
	if (!len)
		return (NULL);
	str = ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

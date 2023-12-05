/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:14:35 by tnicolau          #+#    #+#             */
/*   Updated: 2023/12/05 14:37:29 by tnicolau         ###   ########.fr       */
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

void	*ft_calloc(int nmemb, int size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

void	ft_bzero(void *s, int n)
{
	unsigned char	*str;
	int			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(sizeof(char), (size));
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
	free(s1);
	return (str);
}

// char	*ft_strdup(char *s, char *f)
// {
// 	char	*str;
// 	int		i;
// 	int		size;

// 	size = ft_strlen(s);
// 	i = 0;
// 	str = calloc(sizeof(char), (size + 1));
// 	if (!str)
// 		return (error_management(f));
// 	while (i < (size + 1))
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	free(f);
// 	str[i] = '\0';
// 	return (str);
// }

char	*error_management(char *str1)
{
	free(str1);
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
	// if (length < start)
	// 	return (ft_strdup("", s));
	if (start + len > length)
		len = length - start;
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

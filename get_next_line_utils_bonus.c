/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:46:38 by tnicolau          #+#    #+#             */
/*   Updated: 2023/12/15 13:46:42 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		size;

	i = 0;
	j = 0;
	if (!s1)
		s1 = malloc(sizeof(char) * 1);
	if (!s1 || !s2)
		return (error_management(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (error_management(s1));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

void	*ft_memmove(char *dest, char *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		csrc = (unsigned char *)src;
		cdest = (unsigned char *)dest;
		while (n--)
			*cdest++ = *csrc++;
	}
	else
	{
		csrc = (unsigned char *)src + (n - 1);
		cdest = (unsigned char *)dest + (n - 1);
		while (n--)
			*cdest-- = *csrc--;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;
	int		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

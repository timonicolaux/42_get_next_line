/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:44:39 by tnicolau          #+#    #+#             */
/*   Updated: 2023/12/05 11:43:30 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 5
// # endif

char	*get_next_line(int fd);
char	*save_buffer_left(char *temp, int j);
char	*extract_line(char *temp, char **temp_adress);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strdup(char *s, char *f);
char	*ft_substr(char *s, int start, int len);
void	*ft_calloc(int nmemb, int size);
void	ft_bzero(void *s, int n);
char	*error_management(char *str1);

#endif

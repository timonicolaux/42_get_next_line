/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:46:30 by tnicolau          #+#    #+#             */
/*   Updated: 2023/12/15 13:46:33 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char		*get_next_line(int fd);
char		*store_buffer(int fd, char *temp);
char		*update_temp(char *temp);
char		*extract_line(char	*temp);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
void		*ft_memmove(char *dest, char *src, size_t n);
char		*ft_strdup(char *s);
char		*error_management(char *str);

#endif

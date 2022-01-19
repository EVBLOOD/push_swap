/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:20:03 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/19 22:47:59 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
void	ft_free(void **x);
size_t	ft_strlen_(const char *s);
char	*ft_strjoin_(char *s1, char const *s2);
char	*ft_strchr_(const char *s, int c);
char	*ft_onlyline(char *b, int *c);
char	*ft_the_rest(char *keep, int endofnl);
int		ft_readline(int fd, char *buf, char **keep);
#endif
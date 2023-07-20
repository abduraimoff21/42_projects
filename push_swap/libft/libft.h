/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:00:41 by dabdurai          #+#    #+#             */
/*   Updated: 2023/02/09 19:18:21 by dabdurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);

char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2, int flag);

size_t	ft_strlen(const char *str);

#endif
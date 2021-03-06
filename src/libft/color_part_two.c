/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darabi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:39:50 by darabi            #+#    #+#             */
/*   Updated: 2016/02/22 19:41:02 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strlen_to_open(const char *format, int *i)
{
	int j;

	j = *i;
	while (format[j] && format[j] != '{')
		j++;
	return (j - *i);
}

void			add_char_color(char *str, const char *format, int *i)
{
	int j;

	j = 0;
	while (str[j])
		j++;
	while (format[*i] != '{' && format[*i])
	{
		str[j++] = format[*i];
		++*i;
	}
	str[j] = '\0';
}

char			*changing_malloc_color(char **str, const char *format, int *i)
{
	char	*cpy;

	cpy = NULL;
	cpy = (char *)malloc((ft_strlen(*str) + ft_strlen_to_open(format, i)\
	+ 1) * sizeof(char));
	if (!cpy)
		exit(0);
	cpy[0] = '\0';
	if (*str)
	{
		cpy = ft_strcpy(cpy, *str);
		free(*str);
	}
	add_char_color(cpy, format, i);
	return (cpy);
}

char			*ft_strdup_color(char *color, char **arg)
{
	free(*arg);
	return (ft_strdup(color));
}

char			*add_color(char **str, char *arg)
{
	char	*cpy;
	int		h;
	int		j;
	int		c;

	initialize_three(&h, &j, &c);
	if (!arg)
		return (*str);
	cpy = (char *)malloc((ft_strlen(*str) + ft_strlen(arg) + 1) * sizeof(char));
	if (!cpy)
		exit(0);
	while ((*str)[h])
	{
		cpy[h] = (*str)[h];
		h++;
	}
	while (arg[j] != '\0')
		cpy[h++] = arg[j++];
	cpy[h] = '\0';
	free(*str);
	return (cpy);
}

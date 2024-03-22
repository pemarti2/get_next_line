/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:02:27 by pemarti2          #+#    #+#             */
/*   Updated: 2024/03/09 11:02:30 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_concatenate(char *s1, int letter)
{
	char	*new;
	size_t	i;
	
	i = 0;
	new = malloc(ft_strlen(s1) + 2);
	if (new == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = letter;
	new[i + 1] = '\0';
	return (new);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:21:13 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/08/22 14:06:20 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_ft(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*strjoin_ft(char *line, char *buffer)
{
	char	*new_line;
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	if (buffer[0] == 0)
		return (0);
	new_line = malloc(strlen_ft(line) + strlen_ft(buffer) + 1);
	if (!new_line)
		return (0);
	while (line && line[index1])
	{
		new_line[index1] = line[index1];
		index1++;
	}
	free (line);
	while (buffer && buffer[index2] && buffer[index2] != '\n')
		new_line[index1++] = buffer[index2++];
	if (buffer[index2] == '\n')
		new_line[index1++] = '\n';
	new_line[index1] = '\0';
	return (new_line);
}

int	ft_is_newline(char *buffer)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			check = 1;
			i++;
			break ;
		}
		i++;
	}
	while (buffer[i])
		buffer[j++] = buffer[i++];
	while (j < i)
		buffer[j++] = '\0';
	return (check);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:42:06 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/04/16 12:02:20 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last_pos;

	last_pos = ft_strlen(s);
	while (last_pos >= 0)
	{
		if (s[last_pos] == ((char)c))
		{
			return ((char *)&s[last_pos]);
		}
		last_pos--;
	}
	return (NULL);
}

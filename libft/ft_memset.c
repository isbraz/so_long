/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:19:06 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/04/13 20:24:37 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*ptr;

	index = 0;
	ptr = s;
	while (index < n)
	{
		ptr[index] = (unsigned char)c;
		index++;
	}
	return (s);
}

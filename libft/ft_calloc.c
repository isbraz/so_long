/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:16:09 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/04/26 16:43:52 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	mem_size;

	mem_size = nmemb * size;
	ptr = malloc(mem_size);
	if (ptr != NULL)
		ft_bzero(ptr, mem_size);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:33:19 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/09/17 11:35:16 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2) 
{
	
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
    	}
	return *(unsigned char *)str1 - *(unsigned char *)str2;
}

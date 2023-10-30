/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:57:01 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/04/16 14:51:29 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupstr;

	dupstr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(dupstr))
		return (NULL);
	ft_memcpy(dupstr, s, ft_strlen(s) + 1);
	return (dupstr);
}

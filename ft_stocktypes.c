/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktypes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireznik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:18:42 by nireznik          #+#    #+#             */
/*   Updated: 2020/05/20 10:18:43 by nireznik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_stockchar(const char *content, char c)
{
	char	save;

	save = (char)(malloc(sizeof(char) * 1));
	save = (char)&c;
	return (save);
}

char	*ft_stockstring(const char *content, char *str)
{
	char	*save;

	save = NULL;
	if (!(malloc(sizeof(char) * (ft_strlen(str) + 1))))
		str = NULL;
	save = ft_strcpy(save, str);
	return (save);
}

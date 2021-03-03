/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_precisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireznik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:18:43 by nireznik          #+#    #+#             */
/*   Updated: 2020/05/20 10:18:43 by nireznik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	min(unsigned long x, unsigned long z)
{
	if (x < z)
		return (x);
	return (z);
}

unsigned long   max(unsigned long x, unsigned long z)
{
        if (x > z)
                return (x);
        return (z);
}


unsigned long	ft_strlen(char *str)
{
	int	x;
	
	x = 0;
	if (!(str))
		return (6);
	
	while (str[x])
		x++;
	return (x);
}

unsigned long	ft_intlen(long long x)
{
	if (x < 0)
		return (1 + ft_intlen(-x));
	if (x < 10)
		return (1);
	return (1 + ft_intlen(x / 10));
}

unsigned long	ft_hexalen(unsigned long long x)
{
	if (x < 16)
		return (1);
	return (1 + ft_hexalen(x / 16));
}

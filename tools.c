/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireznik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:18:43 by nireznik          #+#    #+#             */
/*   Updated: 2020/05/20 10:18:43 by nireznik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	writechar(char c, t_mystruct *box)
{
	write(1, &c, 1);
	box->result++;
}

void	writestring(char *str, t_mystruct *box, int maxsize)
{
	int	x;

	x = 0;
	if (!(str))
		str = "(null)";
	while (str[x] && (x < maxsize || maxsize == -1))
		writechar(str[x++], box);
}

void	writeint(long long x, t_mystruct *box)
{
	if (x < 0)
                x = -x;
	if (x >= 0 && x <= 9)
		writechar(x + '0', box);
	else
	{
		writeint(x / 10, box);
		writechar(x % 10 + '0', box);
	}
}

void	writehexa(unsigned long long x, t_mystruct *box, const char *content)
{
	if (x < 10)
		writechar(x + '0', box);
	else if (x < 16)
	{
		if (content[box->x] == 'X')
			writechar(x + 55, box);
		else
			writechar(x + 87, box);
	}
	else
	{
		writehexa(x / 16, box, content);
		writehexa(x % 16, box, content);
	}
}

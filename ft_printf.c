/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireznik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 05:34:42 by nireznik          #+#    #+#             */
/*   Updated: 2020/03/10 10:18:43 by nireznik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *content, ...)
{
	t_mystruct	box;

	box.x = 0;
	box.result = 0;
	va_start(box.ap, content);
	while (content[box.x] != '\0')
	{
		if (content[box.x] == '%' && content[box.x + 1] == '%')
		{
			writechar('%', &box);
			box.x += 2;
		}
		else if (content[box.x] == '%' && content[box.x + 1] != '%')
		{
			box.x++;
			ft_convert(content, &box);
			box.x++;
		}
		else
			writechar(content[box.x++], &box);
	}
	va_end(box.ap);
	return (box.result);
}

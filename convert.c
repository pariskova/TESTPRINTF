/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireznik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:18:42 by nireznik          #+#    #+#             */
/*   Updated: 2020/05/20 10:18:43 by nireznik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(const char *content, t_mystruct *box)
{
	t_preciz	preciz;

	initializ_precisions(&preciz);
	parse_preci(content, &preciz, box);
	if (content[box->x] == 'c')
		writechar_preciz(((char)va_arg(box->ap, unsigned int)), box, &preciz);
	else if (content[box->x] == 's')
		writestring_preciz(va_arg(box->ap, void*), box, &preciz);
	else if (content[box->x] == 'd' || content[box->x] == 'i')
		writeint_preciz(va_arg(box->ap, int), box, &preciz);
	else if (content[box->x] == 'u')
		writeint_preciz(va_arg(box->ap, unsigned int), box, &preciz);
	else if (content[box->x] == 'x' || content[box->x] == 'X')
		writehexa_preciz((va_arg(box->ap, unsigned int)),
			box, &preciz, content);
	else if (content[box->x] == 'p')
	{
		writehexa_preciz((va_arg(box->ap, unsigned long)),
			box, &preciz, content);
	}
}

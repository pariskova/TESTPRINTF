/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireznik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:18:43 by nireznik          #+#    #+#             */
/*   Updated: 2020/05/20 10:18:43 by nireznik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			initializ_precisions(t_preciz *preciz)
{
	preciz->dash = 0;
	preciz->left_nb = -1;
	preciz->right_nb = -1;
	preciz->zero = 0;
	preciz->star = 0;
	preciz->point = 0;
}

static int		parse_int(const char *content, t_mystruct *box)
{
	int		z;

	z = 0;
	while (content[box->x] >= '0' && content[box->x] <= '9')
		z = z * 10 + content[box->x++] - '0';
	return (z);
}

static	int		parse_value(const char *content, t_preciz *preciz,
					t_mystruct *box)
{
	if (content[box->x] == '0')
		preciz->zero = 1;
	if (content[box->x] >= '0' && content[box->x] <= '9')
		return (parse_int(content, box));
	else if (content[box->x] == '*')
	{
		preciz->star = 1;
		box->x++;
		return (va_arg(box->ap, int));
	}
	return (-1);
}

void			parse_preci(const char *content, t_preciz *preciz,
					t_mystruct *box)
{
	if (content[box->x] == '-')
	{
		preciz->dash = 1;
		box->x++;
	}
	preciz->left_nb = parse_value(content, preciz, box);
	if (content[box->x] == '.')
	{
		preciz->point = 1;
		box->x++;
		preciz->right_nb = parse_value(content, preciz, box);
		if (preciz->right_nb == -1)
			preciz->right_nb = 0; 

	}
}

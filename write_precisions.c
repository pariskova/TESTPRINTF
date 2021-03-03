/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_precisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireznik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:18:43 by nireznik          #+#    #+#             */
/*   Updated: 2020/05/20 10:18:43 by nireznik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_spaces(t_mystruct *box, long long x, char c)
{
	while (x > 0)
	{
		writechar(c, box);
		x--;
	}
}

void		writechar_preciz(char c, t_mystruct *box, t_preciz *preciz)
{
	if (!preciz->dash)
		write_spaces(box, preciz->left_nb - 1, ' ');
	writechar(c, box);
	if (preciz->dash)
		write_spaces(box, preciz->left_nb - 1, ' ');
}

void		writestring_preciz(char *str, t_mystruct *box, t_preciz *preciz)
{	
	unsigned long	x;
	
	x = preciz->left_nb - min(ft_strlen(str), preciz->right_nb);
	if (!preciz->dash)
		write_spaces(box, x, ' ');
	writestring(str, box, preciz->right_nb);
	if (preciz->dash)
		write_spaces(box, x, ' ');
}

void		writeint_preciz(long long x, t_mystruct *box, t_preciz *preciz)
{
	int	zero;
	int	spaces;

	zero = (preciz->zero && preciz->right_nb == -1);
	spaces = preciz->left_nb - (preciz->right_nb != -1 ?
			max(preciz->right_nb, ft_intlen(x)) : ft_intlen(x)); 
	if (x < 0 && zero)
		writechar('-', box);
	if (!preciz->dash)
		write_spaces(box, spaces, zero ? '0' : ' ');
	if (x < 0 && !zero)
		writechar('-', box);

	if (x < 0)
		write_spaces(box, preciz->right_nb - ft_intlen(x) + 1, '0');
	else
		write_spaces(box, preciz->right_nb - ft_intlen(x), '0');

	if (!preciz->point || preciz->zero || preciz->dash || preciz->star || (preciz->point && x != 0))	
		writeint(x, box);
	if (preciz->dash)
		write_spaces(box, spaces, ' ');
}

void		writehexa_preciz(unsigned long long x, t_mystruct *box,
				t_preciz *preciz, const char *content)
{
	int	pointeur;
	int	p_value;
	
	pointeur = content[box->x] == 'p';
	p_value = pointeur ? 2 : 0;
	if (x == 0 && pointeur)
	{
		writestring("(nil)", box, 5);
		return ;
	}
	if (!preciz->dash)
		write_spaces(box, preciz->left_nb - ft_hexalen(x) - p_value,
			preciz->zero ? '0' : ' ');
	if (pointeur)
		writestring("0x", box, 2);
	write_spaces(box, preciz->right_nb - ft_hexalen(x) - p_value, '0');
	writehexa(x, box, content);
	if (preciz->dash)
		write_spaces(box, preciz->left_nb - ft_hexalen(x) - p_value, ' ');
}

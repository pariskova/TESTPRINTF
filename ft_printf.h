/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireznik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 05:37:40 by nireznik          #+#    #+#             */
/*   Updated: 2020/03/13 03:42:22 by nireznik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLAGS "-.*0123456789"

typedef struct		s_preciz
{
	int				dash;
	int				left_nb;
	int				right_nb;
	int				zero;
	int				point;
	int				star;
}					t_preciz;

typedef struct		s_list
{
	va_list			ap;
	int				x;
	int				result;
}					t_mystruct;

int					ft_printf(const char *content, ...);
void				ft_convert(const char *content, t_mystruct *box);
void				writechar(char c, t_mystruct *box);
void				writestring(char *str, t_mystruct *box, int maxsize);
void				writeint(long long x, t_mystruct *box);
void				writehexa(unsigned long long x, t_mystruct *box,
						const char *content);
char				*ft_strcpy(char *dest,const char *src);
char				*hexa_to_string(long long x, const char *content,
						t_mystruct *box);
void				initializ_precisions(t_preciz *preciz);
void				parse_preci(const char *content, t_preciz *preciz,
						t_mystruct *box);
unsigned long  		min(unsigned long x, unsigned long z);
unsigned long   	max(unsigned long x, unsigned long z);
unsigned long		ft_strlen(char *str);
unsigned long		ft_intlen(long long x);
unsigned long		ft_hexalen(unsigned long long x);
void				writechar_preciz(char c, t_mystruct *box, t_preciz *preciz);
void				writestring_preciz(char *str, t_mystruct *box,
						t_preciz *preciz);
void				writeint_preciz(long long x, t_mystruct *box,
						t_preciz *preciz);
void				writehexa_preciz(unsigned long long x, t_mystruct *box,
						t_preciz *preciz, const char *content);

#endif

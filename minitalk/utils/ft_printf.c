/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:42:12 by jbellucc          #+#    #+#             */
/*   Updated: 2025/05/08 20:19:05 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putptr(void *ptr, int *count)
{
	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_putnbr_base2((unsigned long long)ptr, "0123456789abcdef", count);
}

void	ft_format(va_list args, const char frm, int *count)
{
	if (frm == 'c')
		ft_putchr(va_arg(args, int), count);
	else if (frm == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (frm == 'd')
		ft_putnbr_base(va_arg(args, int), "0123456789", count);
	else if (frm == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789", count);
	else if (frm == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", count);
	else if (frm == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (frm == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (frm == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (frm == '%')
		ft_putchr('%', count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s ++;
			ft_format(args, *s, &count);
		}
		else
			ft_putchr(*s, &count);
		s ++;
	}
	va_end(args);
	return (count);
}

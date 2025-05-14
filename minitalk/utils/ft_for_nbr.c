/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:45:07 by jbellucc          #+#    #+#             */
/*   Updated: 2025/05/13 14:15:45 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_strlen(char *str)
{
	int	p;

	p = 0;
	while (str[p] != '\0')
		p ++;
	return (p);
}

void	ft_putnbr_base2(unsigned long long n, char *base, int *count)
{
	unsigned long long	len;
	char				c;

	len = (unsigned long long)ft_strlen(base);
	if (len < 2)
		return ;
	if (n >= len)
	{
		ft_putnbr_base2(n / len, base, count);
	}
	c = base[n % len];
	ft_putchr(c, count);
}

void	ft_putnbr_base(long long n, char *base, int *count)
{
	int		len;
	char	c;

	len = ft_strlen(base);
	if (len < 2)
		return ;
	if (n < 0)
	{
		n = -n;
		ft_putchr('-', count);
	}
	if (n >= len)
	{
		ft_putnbr_base(n / len, base, count);
	}
	c = base[n % len];
	ft_putchr(c, count);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*buffer;
	size_t				p;

	buffer = (unsigned char *)s;
	p = 0;
	while (p < n)
	{
		buffer[p] = c;
		p ++;
	}
	return (s);
}

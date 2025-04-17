/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:05:05 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/17 16:38:27 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	atoi(const char *str)
{
	int	p;
	int	ris;
	int	sign;

	p = 0;
	ris = 0;
	sign = 1;
	while ((str[p] == ' ') || (str[p] >= 9 && str[p] <= 13))
		p ++;
	if (str[p] == '-' || str[p] == '+')
	{
		if (str[p] == '-')
		{
			sign = -1;
		}
		p++;
	}
	while ((str[p] >= 48) && (str[p] <= 57))
	{
		ris = ris * 10 + (str[p] - 48);
		p ++;
	}
	return (sign * ris);
}

void	dectobin(int n, int *bin)
{
	int i;
	
	i = 7;
	while (i >= 0)
	{
		if ((n >> i) & 1)
			bin[7 - i] = 1;
		else
			bin[7 - i] = 0;
		i --;
	}
}

int	main(int argc, char **argv)
{
}
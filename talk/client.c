/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:05:05 by jbellucc          #+#    #+#             */
/*   Updated: 2025/05/09 14:22:19 by jbellucc         ###   ########.fr       */
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
		p++;
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
		i--;
	}
}

void	send_char(pid_t pid, char c)
{
	int bin[8];
	int	i;
	
	i = 0;
	dectobin(c, bin);
	while (i < 8)
	{
		if (bin[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	s_pid;

	if (ac != 3)
	{
		ft_printf("numero di argomenti non valido!\n");
		ft_printf("fornire il PID del server e il messaggio\n");
		exit(EXIT_FAILURE);
	}
	s_pid = atoi(av[1]);
	if (s_pid <= 0)
	{
		ft_printf("Error: invalid server PID\n");
		exit(EXIT_FAILURE);
	}
	while (*av[2])
	{
		send_char(s_pid, *av[2]);
		av[2]++;
	}
	send_char(s_pid, *av[2]);
	return (0);
}

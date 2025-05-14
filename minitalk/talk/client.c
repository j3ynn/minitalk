/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:05:05 by jbellucc          #+#    #+#             */
/*   Updated: 2025/05/13 15:20:57 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int		g_received = 0;	//variabile g. indica se il client ha rice vuto una conferma dal server

int	atoi(const char *str) //converte da stringa a intero l'argomento passato 
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

void	dectobin(int n, int *bin) //converte un carattere rapresentato in 
										//ACII in una sequenza di 8 bit e memorizza in un array
{
	int	i;

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

void	ssignal_handler(int sig) 
{
	if (sig == SIGUSR1)
		g_received = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Messaggio ricevuto con successo dal server!\n");
		exit(EXIT_SUCCESS);
	}
}

void	send_char(pid_t pid, char c)
{
	int	bin[8];
	int	i;

	i = 0;
	dectobin(c, bin);	//converte un carattre in 8 bit con dectobin
	while (i < 8)		
	{
		g_received = 0;
		if (bin[i] == 1)	//invia bit come segnale del server (0, 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_received)			//attende conferma
			usleep(50);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t				s_pid;
	struct sigaction	sa;

	if (ac != 3)
		exit(EXIT_FAILURE);
	sa.sa_handler = ssignal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
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
	usleep(500000);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:21:47 by jbellucc          #+#    #+#             */
/*   Updated: 2025/05/12 20:02:22 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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

unsigned char bintodec(unsigned char *bin)
{
    unsigned char n;
    int i;
    
    n = 0;
    i = 0;
    while (i < 8)
    {
        n = n << 1;
        if (bin[i] == 1)
            n = n | 1;
        i++;
    }
    return (n);
}

int convert_char(unsigned char c, int *pos, pid_t client_pid)
{
    *pos = 0;
    if (c == '\0')
    {
        ft_printf("\n%d\n", client_pid);
        kill(client_pid, SIGUSR2);
        return (0);
    }
    write(1, &c, 1);
    return (1);
}

void signal_handler(int sig, siginfo_t *info, void *context)
{
    static int          pos = 0;
    static unsigned char bin[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    static pid_t        client_id = 0;
    unsigned char       res;
    (void)context;
    
    if (client_id != 0 && client_id != info->si_pid)
    {
        pos = 0;
        ft_memset(bin, 0, sizeof(bin));
    }
    client_id = info->si_pid;
    if (sig == SIGUSR1)
        bin[pos] = 1;
    else
        bin[pos] = 0;
    pos++;
    if (pos == 8)
    {
        res = bintodec(bin);
        if (!convert_char(res, &pos, client_id))
            return;
        ft_memset(bin, 0, sizeof(bin));
    }
    kill(client_id, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t			server_pid;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	ft_printf("Waiting for messages...\n");
    sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();

	return (0);
}

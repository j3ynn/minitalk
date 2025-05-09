/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:21:47 by jbellucc          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:27 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

unsigned char bintodec(int *bin)
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
        ft_printf("\n^ ^ ^ MESSAGGIO RICEVUTO DAL CLIENT: %d ^ ^ ^\n\n\n\n", client_pid);
        kill(client_pid, SIGUSR2);
        return (0);
    }
    write(1, &c, 1);
    return (1);
}

void signal_handler(int sig, siginfo_t *info, void *context)
{
    int             pos = 0;
    unsigned char   res = 0;
    int             bin[8];
    pid_t           client_id;
    (void)context;
    
    if (info->si_pid)
        client_id = info->si_pid;
    if (sig == SIGUSR2)
        bin[pos] = 1;
    else
        bin[pos] = 0;
    
    pos++;
    if (pos == 8)
    {
        res = bintodec(bin);
        if (!convert_char(res, &pos, client_id))
            return;
    }
    kill(client_id, SIGUSR1);
}

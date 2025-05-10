/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:21:47 by jbellucc          #+#    #+#             */
/*   Updated: 2025/05/10 18:06:51 by jbellucc         ###   ########.fr       */
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
    static int          pos;
    static unsigned char bin[8];
    static pid_t        client_id;
    unsigned char       res;
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
//da rifare meglio
int main(void)
{
    struct sigaction sa;
    pid_t server_pid;
    
    server_pid = getpid();
    ft_printf("Server PID: %d\n", server_pid);
    ft_printf("In attesa di messaggi...\n");
    
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Errore nella configurazione dei segnali\n");
        return (1);
    }
    
    while (1)
        pause();
    
    return (0);
}
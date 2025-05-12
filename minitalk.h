/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:47:54 by jbellucc          #+#    #+#             */
/*   Updated: 2025/05/12 19:08:13 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

unsigned char bintodec(unsigned char *bin);

void	ft_putnbr_base2(unsigned long long n, char *base, int *count);
void	ft_putnbr_base(long long n, char *base, int *count);
void	ft_putchr(char j, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_format(va_list args, const char frm, int *count);
void	dectobin(int n, int *bin);
void	send_char(pid_t pid, char c);
void	signal_handler(int sig, siginfo_t *info, void *context);
void	*ft_memset(void *s, int c, size_t n);
void	ssignal_handler(int sig);

int		ft_printf(const char *s, ...);
int		ft_strlen(char *str);
int     atoi(const char *str);
int		convert_char(unsigned char c, int *pos, pid_t client_pid);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:47:54 by jbellucc          #+#    #+#             */
/*   Updated: 2025/05/09 17:57:08 by jbellucc         ###   ########.fr       */
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

void	ft_putnbr_base2(unsigned long long n, char *base, int *count);
void	ft_putnbr_base(long long n, char *base, int *count);
void	ft_putchr(char j, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_format(va_list args, const char frm, int *count);
void	dectobin(int n, int *bin);
void	send_char(pid_t pid, char c);

int		ft_printf(const char *s, ...);
int		ft_strlen(char *str);
int     atoi(const char *str);

#endif
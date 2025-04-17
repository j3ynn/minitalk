/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:17:38 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/14 14:31:58 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_putnbr_base2(unsigned long long n, char *base, int *count);
void	ft_putnbr_base(long long n, char *base, int *count);
void	ft_putchr(char j, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_format(va_list args, const char frm, int *count);

int		ft_printf(const char *s, ...);
int		ft_strlen(char *str);

#endif
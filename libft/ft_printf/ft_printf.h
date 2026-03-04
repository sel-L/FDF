/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:08:09 by selow             #+#    #+#             */
/*   Updated: 2025/08/09 20:39:04 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// main control functions
int	ft_printf_fd(int fd, const char *format, ...);
int	handle_format(const char **format, va_list ap, int fd);

// printing specifiers
int	put_c(char c, int fd);
int	put_s(char *str, int fd);
int	ft_putnbr(long n, int fd);
int	put_p(void *ptr, int fd);
int	put_u(unsigned int n, int fd);
int	put_x(unsigned int n, int fd);
int	put_big_x(unsigned int n, int fd);
int	put_u(unsigned int n, int fd);

#endif

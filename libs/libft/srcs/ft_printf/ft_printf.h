/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:51:32 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 14:41:22 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFFER_SIZE 42

void	cat(char *buffer, char chr);
void	cat_str(char *buffer, char *str);
char	*stoa(char *str);
char	*ptoa(void *ptr);
char	*ctoa(char chr);
char	*m_itoa(long n);
char	*lhextoa(unsigned int n);
char	*uhextoa(unsigned int n);
int		ft_printf(const char *str, ...);
int		append_chr(char chr, int len);
int		append_str(char *str);

#endif

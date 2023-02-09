/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:14:11 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 14:45:17 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdint.h>
# include "../../libs/libft/libft.h"

# define DBIT_DELAY 100
# define BIT_TIMEOUT 500

extern int32_t	g_transmitted;

void	send_string(int pid, char *str);
void	send_bit(int pid, uint8_t bit);
void	send_byte(int pid, uint8_t byte);
void	send_byte_force(int pid, uint8_t byte, uint32_t delay);
void	send_pid(int spid);
void	bit_received(int signal);

#endif

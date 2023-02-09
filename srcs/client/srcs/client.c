/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:08:38 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 14:21:00 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

void	send_string(int pid, char *str)
{
	while (*str)
		send_byte(pid, (*(str++)));
	send_byte(pid, '\n');
	send_byte(pid, 0);
}

void	send_bit(int pid, uint8_t bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(10000);
}

void	send_byte(int pid, uint8_t byte)
{
	uint8_t	count;

	count = 0;
	while (count < 8)
	{
		if (byte & (1 << count))
			send_bit(pid, 1);
		else
			send_bit(pid, 0);
		++count;
	}
}

void	send_byte_force(int pid, uint8_t byte, uint32_t delay)
{
	uint8_t	count;

	count = 0;
	while (count < 8)
	{
		if (byte & (1 << count))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(delay);
		++count;
	}
}

void	bit_received(int signal)
{
	(void)(signal);
	g_transmitted++;
}

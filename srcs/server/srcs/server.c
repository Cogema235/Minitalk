/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:08:57 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/09 13:55:21 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

void	build_cpid(uint8_t byte)
{
	static uint8_t	recieved = 0;

	++recieved;
	if (recieved == 1)
		g_client.pid |= (int32_t)byte;
	else if (recieved == 2)
		g_client.pid |= ((int32_t)byte) << 8;
	else if (recieved == 3)
		g_client.pid |= ((int32_t)byte) << 16;
	else
	{
		g_client.pid |= ((int32_t)byte) << 24;
		g_client.defined = 1;
		ft_printf("\nMessage de %d :\n\n", g_client.pid);
		recieved = 0;
	}
}

static	void	end_(t_dynastring *msg, uint8_t *allocated, uint32_t *recieved)
{
	print_str(msg);
	delete_dynastring(msg);
	*allocated = 0;
	ft_printf("\nFin du message, %d octets recus.\n\nPID : "\
			"%d. En ecoute...\n", recieved - 6, getpid());
	g_client.pid = 0;
	g_client.defined = 0;
	*recieved = 0;
}

void	byte_handler(uint8_t byte)
{
	static t_dynastring	*message;
	static uint32_t		recieved = 0;
	static uint8_t		allocated = 0;

	++recieved;
	if (recieved <= 4)
		build_cpid(byte);
	else if (!byte)
	{
		end_(message, &allocated, &recieved);
	}
	else
	{
		if (allocated)
			dappend_chr(message, byte);
		else
		{
			message = dynastring(10);
			if (!message)
				exit(0);
			allocated = 1;
			dappend_chr(message, byte);
		}
	}	
}

void	bit_handler(int signal)
{
	static uint8_t	byte = 0;
	static uint8_t	count = 0;
	static uint8_t	mask = 1;

	if (signal == SIGUSR1)
		byte |= mask;
	++count;
	if (count == 8)
	{
		byte_handler(byte);
		byte = 0;
		count = 0;
		mask = 1;
	}
	else
		mask <<= 1;
	if (g_client.defined)
		kill(g_client.pid, SIGUSR1);
}

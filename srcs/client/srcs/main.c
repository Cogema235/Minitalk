/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:10:05 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 14:19:55 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

int32_t	g_transmitted = 0;

static int	is_uint(char *str)
{
	int	digits;
	int	len;

	len = 0;
	digits = 0;
	while (str[len])
	{
		if (ft_isdigit(str[len]))
			digits++;
		len++;
	}
	return (digits && len == digits);
}

int	main(int ac, char **av)
{
	char	*msg;
	int		pid;

	signal(SIGUSR1, bit_received);
	if (ac == 3 && is_uint(av[1]) && ft_atoi(av[1]))
	{
		pid = ft_atoi(av[1]);
		msg = av[2];
		send_pid(pid);
		send_string(pid, msg);
		g_transmitted = (g_transmitted / 8) - 2;
		if (g_transmitted < 0)
			g_transmitted = 0;
		ft_printf("\n%d octets sur %d transmis a %d depuis %d.\n", \
			g_transmitted, ft_strlen(msg), pid, getpid());
	}
	else
		ft_putstr_fd("Mauvais parametres. utilisation : \
            [CLIENT] [PID] [MESSAGE]\n", 1);
	return (0);
}

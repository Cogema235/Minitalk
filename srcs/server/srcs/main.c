/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:54:17 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 14:13:52 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

t_client	g_client;

int	main(void)
{
	g_client.pid = 0;
	g_client.defined = 0;
	ft_printf("PID : %d. En ecoute...\n", getpid());
	signal(SIGUSR2, bit_handler);
	signal(SIGUSR1, bit_handler);
	while (1)
		;
	return (0);
}

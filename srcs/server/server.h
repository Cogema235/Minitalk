/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:23:52 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 14:44:19 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdint.h>
# include "../../libs/libft/libft.h"

typedef struct s_client
{
	uint8_t	defined;
	int		pid;
}	t_client;

extern t_client	g_client;

void	bit_handler(int signal);
void	byte_handler(uint8_t byte);

#endif

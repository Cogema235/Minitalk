/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:42:25 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 14:21:06 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

void	send_pid(int spid)
{
	uint32_t	pid;

	pid = getpid();
	send_byte_force(spid, (uint8_t)pid, DBIT_DELAY);
	send_byte_force(spid, (uint8_t)(pid >> 8), DBIT_DELAY);
	send_byte_force(spid, (uint8_t)(pid >> 16), DBIT_DELAY);
	send_byte_force(spid, (uint8_t)(pid >> 24), DBIT_DELAY);
}

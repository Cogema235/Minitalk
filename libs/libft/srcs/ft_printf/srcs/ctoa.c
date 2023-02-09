/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:14:17 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/08 16:15:07 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ctoa(char chr)
{
	static char	output[2];

	output[1] = 0;
	output[0] = chr;
	return (output);
}

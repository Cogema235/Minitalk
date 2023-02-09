/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:35:48 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:31:06 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdint.h>

double	ft_atof(char *str)
{
	uint8_t	declen;
	double	int_part;
	double	dec_part;
	char	*dec_part_start;

	int_part = ft_atoi(str);
	dec_part_start = ft_strchr(str, '.');
	if (!dec_part_start)
		return ((int)int_part);
	dec_part = ft_atoi(++dec_part_start);
	declen = ft_strlen(dec_part_start);
	if (int_part < 0 || str[0] == '-')
		dec_part = -dec_part;
	return (int_part + dec_part / ft_pow(10, declen));
}

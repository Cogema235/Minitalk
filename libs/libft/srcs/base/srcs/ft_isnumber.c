/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:33:52 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:31:32 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isnumber(char *str)
{
	int	points;
	int	i;

	points = 0;
	if (!ft_isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		if (!ft_isdigit(str[1]))
			return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.' && !points)
				points++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

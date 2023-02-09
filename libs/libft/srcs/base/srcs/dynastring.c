/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynastring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:52:46 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/08 19:03:35 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dynastring	*dynastring(uint32_t size)
{
	t_dynastring	*dynstr;

	dynstr = malloc(sizeof(t_dynastring));
	if (!dynstr)
		return (NULL);
	dynstr->str = malloc(size);
	if (!dynstr->str)
	{
		free(dynstr);
		return (NULL);
	}
	dynstr->allocated_size = size;
	dynstr->filled_size = 0;
	return (dynstr);
}

t_dynastring	*print_str(t_dynastring *dynstr)
{
	write(STDOUT_FILENO, dynstr->str, dynstr->filled_size);
	return (dynstr);
}

void	delete_dynastring(t_dynastring *dynstr)
{
	free(dynstr->str);
	free(dynstr);
}

static void	copy(char *dest, char *source, uint32_t size)
{
	uint32_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = source[i];
		++i;
	}
}

t_dynastring	*dappend_chr(t_dynastring *dynstr, char chr)
{
	char	*new_str;

	if (dynstr->filled_size == dynstr->allocated_size)
	{
		new_str = malloc(dynstr->allocated_size * 2);
		if (!new_str)
			return (NULL);
		copy(new_str, dynstr->str, dynstr->filled_size);
		free(dynstr->str);
		dynstr->str = new_str;
		dynstr->str[dynstr->filled_size] = chr;
		dynstr->allocated_size *= 2;
		dynstr->filled_size++;
		return (dynstr);
	}
	dynstr->str[dynstr->filled_size] = chr;
	++(dynstr->filled_size);
	return (dynstr);
}

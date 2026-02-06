/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:45:35 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/06 11:49:56 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	check_arg(char **arg)
{
	int	i;
	int	conv_arg;

	i = 1;
	while (i != 8)
	{
		conv_arg = atoi(arg[i]);
		if (conv_arg >= 1)
		{
			i++;
		}
		else
			return (fprintf(stderr, "ERROR: Invalid argument (%s)", arg[i]), 1);
	}
	if (strcmp("fifo", arg[i]) == 0 || strcmp("edf", arg[i]) == 0)
		return (0);
	else
		return (fprintf(stderr, "ERROR: Invalid argument (%s). Use only 'fifo' "
				"or 'edf'", arg[i]), 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:45:35 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/11 10:47:54 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	check_arg(char **arg, t_data *data)
{
	int	i;
	int	conv_arg[8];

	i = 1;
	while (i != 8)
	{
		conv_arg[i - 1] = atoi(arg[i]);
		if (conv_arg[i - 1] >= 1)
			i++;
		else
			return (fprintf(stderr, "ERROR: Invalid argument (%s)", arg[i]), 1);
	}
	if (init_struct(conv_arg, data) == 1)
		return (1);
	if (strcmp("fifo", arg[i]) == 0 || strcmp("edf", arg[i]) == 0)
		data->scheduler = arg[i];
	else
		return (fprintf(stderr, "ERROR: Invalid argument (%s). Use only 'fifo' "
				"or 'edf'", arg[i]), 1);
	return (0);
}

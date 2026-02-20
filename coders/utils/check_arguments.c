/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:45:35 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/20 19:38:26 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	parse_data(t_data *data, int *arg);

int	check_arg(t_data *data, char **arg)
{
	int	i;
	int	parsed_arg[8];

	i = 1;
	while (i != 8)
	{
		parsed_arg[i - 1] = atoi(arg[i]);
		if (parsed_arg[i - 1] >= 1)
		{
			if (i == 1 && parsed_arg[i - 1] >= MAX_CODERS)
				return (print_error(STR_ERR_INV_ARG, arg[i], data));
			i++;
		}
		else
			return (print_error(STR_ERR_INV_ARG, arg[i], data));
	}
	if (parse_data(data, parsed_arg) == 1 || init_struct(data) == 1)
		return (1);
	if (strcmp(FIFO, arg[i]) == 0 || strcmp(EDF, arg[i]) == 0)
		data->scheduler = arg[i];
	else
		return (print_error(STR_ERR_INV_ARG, arg[i], data));
	return (0);
}

static int	parse_data(t_data *data, int *arg)
{
	data->coder = malloc(sizeof(t_coder) * arg[0]);
	if (data->coder == NULL)
		return (print_error(STR_ERR_MALLOC, NULL, data));
	data->dongle = malloc(sizeof(t_dongle) * arg[0]);
	if (data->dongle == NULL)
		return (print_error(STR_ERR_MALLOC, NULL, data));
	data->nbr_coders = arg[0];
	data->nbr_dongle = arg[0];
	data->burnout_max = arg[1];
	data->time_comp = arg[2];
	data->time_debug = arg[3];
	data->time_refac = arg[4];
	data->compile_required = arg[5];
	data->dongle_cooldown = arg[6];
	return (0);
}

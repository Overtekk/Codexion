/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:45:35 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/07 16:04:03 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static	int	init_struct(int *value, t_data *data);
static	void	create_coders_and_dongle(t_data *data);

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

static	int	init_struct(int *value, t_data *data)
{
	data->coder = calloc(1, sizeof(t_coder) * value[0]);
	if (data->coder == NULL)
		return (1);
	data->dongle = calloc(1, sizeof(t_dongle) * value[0]);
	if (data->dongle == NULL)
		return (1);
	data->nbr_coders = value[0];
	data->nbr_dongle = value[0];
	data->burnout_max = value[1];
	data->time_comp = value[2];
	data->time_debug = value[3];
	data->time_refac = value[4];
	data->compile_required = value[5];
	data->dongle_cooldown = value[6];
	data->simulation_active = 1;
	create_coders_and_dongle(data);
	return (0);
}

static	void	create_coders_and_dongle(t_data *data)
{
	int	count;

	count = 0;
	while (data->nbr_coders != count)
	{
		data->coder[count].id = count + 1;
		data->coder[count].time_bournout = data->burnout_max;
		data->coder[count].code_compiled = 0;
		data->coder[count].data = data;
		count++;
	}
	count = 0;
	while (data->nbr_dongle != count)
	{
		data->dongle[count].id = 'A' + count;
		data->dongle[count].cooldown = data->dongle_cooldown;
		data->dongle[count].data = data;
		count++;
	}
}

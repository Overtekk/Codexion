/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:46:33 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/17 13:30:57 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	create_coders_and_dongle(t_data *data);
static void	fill_dongle_id(char *id_str, int index);

int	init_struct(int *value, t_data *data)
{
	data->coder = malloc(sizeof(t_coder) * value[0]);
	if (data->coder == NULL)
		return (print_error(STR_ERR_MALLOC, NULL, data));
	data->dongle = malloc(sizeof(t_dongle) * value[0]);
	if (data->dongle == NULL)
		return (print_error(STR_ERR_MALLOC, NULL, data));
	data->nbr_coders = value[0];
	data->nbr_dongle = value[0];
	data->burnout_max = value[1];
	data->time_comp = value[2];
	data->time_debug = value[3];
	data->time_refac = value[4];
	data->compile_required = value[5];
	data->dongle_cooldown = value[6];
	data->simulation_active = 1;
	data->start_time = get_time_ms();
	data->queue_control.first = NULL;
	data->queue_control.last = NULL;
	create_coders_and_dongle(data);
	return (0);
}

static void	create_coders_and_dongle(t_data *data)
{
	int	count;
	int	next_id;

	count = 0;
	while (data->nbr_coders != count)
	{
		data->coder[count].id = count + 1;
		data->coder[count].time_bournout = get_time_ms();
		data->coder[count].code_compiled = 0;
		data->coder[count].have_finished = 0;
		data->coder[count].data = data;
		data->coder[count].left_dongle = NULL;
		data->coder[count].right_dongle = NULL;
		if (data->nbr_coders > 1)
		{
			next_id = (count + 1) % data->nbr_coders;
			if (count < next_id)
			{
				data->coder[count].left_dongle = &data->dongle[count];
				data->coder[count].right_dongle = &data->dongle[next_id];
			}
			else
			{
				data->coder[count].left_dongle = &data->dongle[next_id];
				data->coder[count].right_dongle = &data->dongle[count];
			}
		}
		else
			data->coder[count].left_dongle = &data->dongle[count];
		count++;
	}
	count = 0;
	while (data->nbr_dongle != count)
	{
		fill_dongle_id(data->dongle[count].id, count);
		data->dongle[count].cooldown = 0;
		data->dongle[count].data = data;
		count++;
	}
}

static void	fill_dongle_id(char *id_str, int index)
{
	int		i;
	int		len;
	char	temp[10];

	i = 0;
	while (index >= 0)
	{
		temp[i++] = (index % 26) + 'A';
		index = (index / 26) - 1;
	}
	temp[i] = '\0';
	len = i;
	i = 0;
	while (i < len)
	{
		id_str[i] = temp[len - 1 - i];
		i++;
	}
	id_str[i] = '\0';
}

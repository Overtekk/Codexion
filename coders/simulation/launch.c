/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:37:16 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/11 10:52:27 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	start_simulation(t_data *data)
{
	int	index;

	while (data->simulation_active == 1)
	{
		index = 0;
		while (data->nbr_coders != index)
		{
			if ((get_time_ms() - data->coder[index].time_bournout) > data->burnout_max)
			{
				print_logs(data->coder[index].id, "burns_out", data);
				data->simulation_active = 0;
				break;
			}
			else
				index++;
		}
		usleep(1000);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:37:16 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/07 16:00:18 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	start_simulation(t_data *data)
{
	int	index;

	index = 0;
	while (data->simulation_active == 1)
	{
		while (data->nbr_coders != index)
		{
			if ((get_time_ms() - data->coder[index].time_bournout) > data->burnout_max)
				index++;
			else
			{
				printf("Coder %d a fait un burn out", data->coder[index].id);
				break;
			}
		}
		break;
	}
	return (0);
}

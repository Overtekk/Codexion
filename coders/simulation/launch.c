/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:37:16 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/17 12:43:47 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*start_simulation(void *arg)
{
	t_data	*data;
	int		index;
	int		finish;

	data = (t_data *)arg;
	while (get_simulation(data) == 1)
	{
		index = 0;
		finish = 0;
		while (data->nbr_coders != index)
		{
			if (data->coder[index].have_finished == 1)
				finish++;
			else if ((get_time_ms() - get_burnout(&data->coder[index])) > data->burnout_max)
			{
				pthread_mutex_lock(&data->mutex_simu);
				data->simulation_active = 0;
				pthread_mutex_unlock(&data->mutex_simu);
				pthread_cond_broadcast(&data->queue_control.cond);
				print_logs(data->coder[index].id, 0, ACT_BURNS, data);
				return (NULL);
			}
			else
				index++;
		}
		if (finish == data->nbr_coders)
		{
			pthread_mutex_lock(&data->mutex_simu);
			data->simulation_active = 0;
			pthread_mutex_unlock(&data->mutex_simu);
			pthread_cond_broadcast(&data->queue_control.cond);
			printf(LOG_SUCCESS "\n");
			return (NULL);
		}
		usleep(300);
	}
	return (NULL);
}

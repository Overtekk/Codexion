/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:37:16 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/20 13:39:51 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	check_burns_out(t_data *data, int *finish);
static void	stop_simulation(t_data *data);

void	*monitoring_simulation(void *arg)
{
	t_data	*data;
	int		finish;

	data = (t_data *)arg;
	while (get_simulation(data) == 1)
	{
		if (check_burns_out(data, &finish) == 1)
			return (NULL);
		if (finish == data->nbr_coders)
		{
			stop_simulation(data);
			printf(LOG_SUCCESS "\n");
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

static int	check_burns_out(t_data *data, int *finish)
{
	int	index;

	index = 0;
	*finish = 0;
	while (data->nbr_coders != index)
	{
		if (get_have_finished(&data->coder[index]) == 1)
			(*finish)++;
		else if ((get_time_ms() - get_burnout(&data->coder[index]))
			> data->burnout_max)
		{
			stop_simulation(data);
			print_logs(data->coder[index].id, 0, ACT_BURNS, data);
			return (1);
		}
		index++;
	}
	return (0);
}

static void	stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->mutex_simu);
	data->simulation_active = 0;
	pthread_mutex_unlock(&data->mutex_simu);
	pthread_cond_broadcast(&data->queue_control.cond);
	pthread_cond_broadcast(&data->heap_control.cond);
}

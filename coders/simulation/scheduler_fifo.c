/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler_fifo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:30:39 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/17 13:54:20 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	fifo_add_queue(t_data *data, t_coder *coder);

int	scheduler_fifo(t_data *data, t_coder *coder, char *action)
{
	pthread_mutex_lock(&data->queue_control.lock);
	if (strcmp(action, ADD_QUEUE) == 0)
	{
		fifo_add_queue(data, coder);
	}
	else if (strcmp(action, REMOVE_QUEUE) == 0)
	{
		remove_from_queue(&data->queue_control);
		pthread_cond_broadcast(&data->queue_control.cond);
	}
	pthread_mutex_unlock(&data->queue_control.lock);
	return (0);
}

static void	fifo_add_queue(t_data *data, t_coder *coder)
{
	add_to_queue(&data->queue_control, coder);
	while (get_simulation(data) == 1
		&& (data->queue_control.first->coder != coder
			|| take_dongle(coder) == 1))
	{
		if (get_simulation(data) == 1
			&& data->queue_control.first->coder == coder)
		{
			pthread_mutex_unlock(&data->queue_control.lock);
			usleep(1000);
			pthread_mutex_lock(&data->queue_control.lock);
		}
		else
			pthread_cond_wait(&data->queue_control.cond,
				&data->queue_control.lock);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:30:39 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/17 12:09:09 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	scheduler_fifo(t_data *data, t_coder *coder, char *action)
{
	pthread_mutex_lock(&data->queue_control.lock);
	if (strcmp(action, ADD_QUEUE) == 0)
	{
		add_to_queue(&data->queue_control, coder);
		while (data->queue_control.first->coder != coder || take_dongle(coder) == 1)
			pthread_cond_wait(&data->queue_control.cond, &data->queue_control.lock);
	}
	else if (strcmp(action, REMOVE_QUEUE) == 0)
	{
		remove_from_queue(&data->queue_control);
		pthread_cond_broadcast(&data->queue_control.cond);
	}
	pthread_mutex_unlock(&data->queue_control.lock);
	return (0);
}

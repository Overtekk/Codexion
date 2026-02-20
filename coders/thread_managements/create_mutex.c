/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:42:31 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/20 14:12:21 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	init_mutex_cond(t_data *data);
static void	init_dongles_mutex(t_data *data);

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&data->mutex_print, NULL);
	pthread_mutex_init(&data->mutex_simu, NULL);
	pthread_mutex_init(&data->queue_control.lock, NULL);
	pthread_mutex_init(&data->heap_control.lock, NULL);
	init_dongles_mutex(data);
	init_mutex_cond(data);
}

static void	init_mutex_cond(t_data *data)
{
	pthread_cond_init(&data->queue_control.cond, NULL);
	pthread_cond_init(&data->heap_control.cond, NULL);
}

static void	init_dongles_mutex(t_data *data)
{
	int	index;

	index = 0;
	while (index != data->nbr_dongle)
	{
		pthread_mutex_init(&data->dongle[index].lock, NULL);
		pthread_mutex_init(&data->coder[index].mutex_burnout, NULL);
		pthread_mutex_init(&data->coder[index].mutex_finish, NULL);
		pthread_mutex_init(&data->coder[index].mutex_deadline, NULL);
		index++;
	}
}

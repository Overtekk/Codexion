/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:35:21 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/17 11:11:33 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	destroy_mutex(t_data *data)
{
	int	index;

	index = 0;
	while (data->nbr_coders != index)
	{
		pthread_mutex_destroy(&data->dongle[index].lock);
		pthread_mutex_destroy(&data->coder[index].mutex_burnout);
		index++;
	}
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_simu);
	pthread_mutex_destroy(&data->queue_control.lock);
	pthread_cond_destroy(&data->queue_control.cond);
	return (0);
}

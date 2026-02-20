/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler_edf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:40:41 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/20 14:37:47 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	scheduler_edf_add(t_data *data, t_coder *coder)
{
	t_heap	*controler;

	controler = &data->heap_control;
	pthread_mutex_lock(&controler->lock);
	heap_push(controler, coder);
	pthread_cond_broadcast(&controler->cond);
	while (get_simulation(data) == 1
			&& (controler->tree[0] != coder || take_dongle(coder) == 1))
	{
		if (get_simulation(data) == 1 && controler->tree[0] == coder)
		{
			pthread_mutex_unlock(&controler->lock);
			usleep(1000);
			pthread_mutex_lock(&controler->lock);
		}
		else
			pthread_cond_wait(&controler->cond, &controler->lock);
	}
	heap_pop(controler);
	pthread_cond_broadcast(&controler->cond);
	pthread_mutex_unlock(&controler->lock);
}

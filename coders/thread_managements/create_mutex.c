/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:42:31 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/11 10:39:45 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_mutex_for_dongle(t_data *data)
{
	int	index;

	index = 0;
	while (data->nbr_dongle != index)
	{
		pthread_mutex_init(&data->dongle[index].lock, NULL);
		index++;
	}
	return (0);
}

int	init_mutex_print(t_data *data)
{
	pthread_mutex_init(&data->mutex_print, NULL);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:42:31 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/06 16:56:18 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_mutex_for_dongle(t_data *data)
{
	int	index;

	index = 0;
	while (data->nbr_dongle != index)
	{
		pthread_mutex_init(data->dongle[index].lock, NULL);
		index++;
	}
	return (0);
}

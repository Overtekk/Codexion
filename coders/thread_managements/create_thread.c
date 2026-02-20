/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:47:10 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/20 13:53:02 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_thread(t_data *data)
{
	int	index;

	index = 0;
	pthread_create(&data->monitoring_id, NULL, monitoring_simulation, data);
	while (index != data->nbr_coders)
	{
		pthread_create(&data->coder[index].thread_id, NULL, coder_thread,
			&data->coder[index]);
		index++;
	}
}

void	join_thread(t_data *data)
{
	int	index;

	index = 0;
	pthread_join(data->monitoring_id, NULL);
	while (index != data->nbr_coders)
	{
		pthread_join(data->coder[index].thread_id, NULL);
		index++;
	}
}

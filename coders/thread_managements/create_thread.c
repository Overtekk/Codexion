/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:47:10 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/07 15:47:07 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


int	init_thread(t_data *data)
{
	int	index;

	index = 0;
	while (data->nbr_coders != index)
	{
		pthread_create(&data->coder[index].thread_id, NULL, coder_goal, &data->coder[index]);
		index++;
	}
	index = 0;
	while (data->nbr_coders != index)
	{
		pthread_join(data->coder[index].thread_id, NULL);
		index++;
	}
	return (0);
}

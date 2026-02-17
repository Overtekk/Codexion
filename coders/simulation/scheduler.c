/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:30:39 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/17 09:40:40 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	scheduler_fifo(t_data *data, t_coder *coder, char *action)
{
	if (strcmp(action, ADD_QUEUE) == 0)
		add_to_queue(&data->queue_control, &coder);
	if (strcmp(action, REMOVE_QUEUE) == 0)
		remove_from_queue(&data);
	return (0);
}

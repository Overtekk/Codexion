/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:36:58 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/17 08:56:19 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	debug_print_queue(t_queue_manager *manager)
{
	int		count;
	t_queue	*current;

	count = 0;
	current = manager->first;
	while (current != NULL)
	{
		printf("[Queue %d] Coder %d\n", count, current->coder->id);
		count++;
		current = current->next;
	}
}

void	debug_test_add_queue(t_data *data, t_coder *coder)
{
	add_to_queue(&data->queue_control, &coder[0]);
	add_to_queue(&data->queue_control, &coder[1]);
}

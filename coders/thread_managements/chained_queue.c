/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:12:27 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/20 09:31:27 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	add_to_queue(t_queue_manager *manager, t_coder *coder_to_add)
{
	t_queue	*node;

	node = malloc(sizeof(t_queue));
	if (node == NULL)
		return (1);
	node->coder = coder_to_add;
	node->next = NULL;
	if (manager->first == NULL)
	{
		manager->first = node;
		manager->last = node;
	}
	else
	{
		manager->last->next = node;
		manager->last = node;
	}
	return (0);
}

int	remove_from_queue(t_queue_manager *manager)
{
	t_queue	*temp;

	if (manager->first == NULL)
		return (1);
	temp = manager->first;
	manager->first = temp->next;
	if (manager->first == NULL)
		manager->last = NULL;
	free (temp);
	return (0);
}



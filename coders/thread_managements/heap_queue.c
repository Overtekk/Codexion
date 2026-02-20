/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:31:51 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/20 18:45:26 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static	int		heap_compare(t_coder *curr_coder, t_coder *coder);
static	void	heap_swap(t_coder **tree, int i, int j);

void	heap_push(t_heap *manager, t_coder *coder)
{
	int	i;

	i = manager->size;
	manager->tree[i] = coder;
	manager->size += 1;
	while (i > 0)
	{
		if (heap_compare(manager->tree[i], manager->tree[(i - 1) / 2]))
		{
			heap_swap(manager->tree, i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
		else
			break ;
	}
}

void	heap_pop(t_heap *manager, t_coder *coder)
{
	int i;

	i = 0;
	while (i < manager->size)
	{
		if (manager->tree[i] == coder)
			break ;
		i++;
	}
	if (i == manager->size)
		return ;
	manager->size--;
	manager->tree[i] = manager->tree[manager->size];
	while (i > 0 && heap_compare(manager->tree[i], manager->tree[(i - 1) / 2]))
	{
		heap_swap(manager->tree, i, (i - 1) / 2);
		i = (i - 1) / 2;
	}
	while ((i * 2) + 1 < manager->size)
	{
		int left = (i * 2) + 1;
		int right = (i * 2) + 2;
		int smallest = left;
		if (right < manager->size && heap_compare(manager->tree[right], manager->tree[left]))
			smallest = right;
		if (heap_compare(manager->tree[smallest], manager->tree[i]))
		{
			heap_swap(manager->tree, i, smallest);
			i = smallest;
		}
		else
			break ;
	}
}

static	int	heap_compare(t_coder *curr_coder, t_coder *coder)
{
	return (get_burnout(curr_coder) < get_burnout(coder));
}

static	void	heap_swap(t_coder **tree, int i, int j)
{
	t_coder *temp;

	temp = tree[i];
	tree[i] = tree[j];
	tree[j] = temp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scheduler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:08:50 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/20 12:48:26 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_fifo(t_data *data)
{
	if (strcmp(FIFO, data->scheduler) == 0)
		return (1);
	return (0);
}

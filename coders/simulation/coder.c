/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:40:21 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/07 16:01:40 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_goal(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	coder->time_bournout = get_time_ms() - coder->data->time_comp;
	coder->time_bournout = get_time_ms() - coder->data->time_debug;
	coder->time_bournout = get_time_ms() - coder->data->time_refac;
	return NULL;
}

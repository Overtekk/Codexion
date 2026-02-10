/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:40:21 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/10 16:30:40 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_goal(void *arg)
{
	t_coder	*coder;
	long long	time;

	coder = (t_coder *)arg;
	time = get_time_ms();
	coder->time_bournout = get_time_ms() - coder->data->time_comp;
	print_logs(time - coder->data->time, coder->id, "compile");
	usleep(coder->data->time_comp * 1000);

	time = get_time_ms();
	coder->time_bournout = get_time_ms() - coder->data->time_debug;
	print_logs(time - coder->data->time, coder->id, "debug");
	usleep(coder->data->time_debug * 1000);

	time = get_time_ms();
	coder->time_bournout = get_time_ms() - coder->data->time_refac;
	print_logs(time - coder->data->time, coder->id, "refac");
	usleep(coder->data->time_refac * 1000);
	return NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:40:21 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/11 09:55:02 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_goal(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	print_logs(coder->id, "compile", coder->data);
	usleep(coder->data->time_comp * 1000);

	print_logs(coder->id, "debug", coder->data);
	usleep(coder->data->time_debug * 1000);

	print_logs(coder->id, "refac", coder->data);
	usleep(coder->data->time_refac * 1000);
	return NULL;
}

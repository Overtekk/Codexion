/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:40:21 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/13 09:36:24 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_goal(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	while (get_simulation(coder->data) == 1 && coder->code_compiled < coder->data->compile_required)
	{
		set_burnout(coder);
		print_logs(coder->id, "compile", coder->data);
		coder->code_compiled += 1;
		usleep(coder->data->time_comp * 1000);

		print_logs(coder->id, "debug", coder->data);
		usleep(coder->data->time_debug * 1000);

		print_logs(coder->id, "refac", coder->data);
		usleep(coder->data->time_refac * 1000);
	}
	return NULL;
}

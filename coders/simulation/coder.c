/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:40:21 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/14 11:47:49 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	take_dongle(t_coder *coder);

void	*coder_goal(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	while (get_simulation(coder->data) == 1
		&& coder->code_compiled < coder->data->compile_required)
	{
		if (take_dongle(coder) == 0)
		{
			set_burnout(coder);
			print_logs(coder->id, 0, "compile", coder->data);
			coder->code_compiled += 1;
			usleep(coder->data->time_comp * 1000);
			reset_dongle_cooldown(coder, coder->data);
			print_logs(coder->id, 0, "debug", coder->data);
			usleep(coder->data->time_debug * 1000);
			print_logs(coder->id, 0, "refac", coder->data);
			usleep(coder->data->time_refac * 1000);
		}
		else
			usleep(500);
	}
	return (NULL);
}

static int	take_dongle(t_coder *coder)
{
	if (try_take_dongle(coder->left_dongle, coder->data) == 0)
	{
		print_logs(coder->id, coder->left_dongle->id, "takedongle", coder->data);
		if (try_take_dongle(coder->right_dongle, coder->data) == 0)
		{
			print_logs(coder->id, coder->right_dongle->id, "takedongle", coder->data);
			return (0);
		}
		else
		{
			pthread_mutex_unlock(&coder->left_dongle->lock);
			return (1);
		}
	}
	return (1);
}

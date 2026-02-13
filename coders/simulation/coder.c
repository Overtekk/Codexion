/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:40:21 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/13 17:16:57 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static	void	unlock_dongles(t_coder *coder);

void	*coder_goal(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	while (get_simulation(coder->data) == 1 && coder->code_compiled < coder->data->compile_required)
	{
		if (try_take_left_dongle(coder->left_dongle, coder->data) == 0)
		{
			print_logs(coder->id, "takedongle", coder->data);
			if (try_take_right_dongle(coder->right_dongle, coder->data) == 0)
			{
				print_logs(coder->id, "takedongle", coder->data);
				set_burnout(coder);
				print_logs(coder->id, "compile", coder->data);
				coder->code_compiled += 1;
				unlock_dongles(coder);
				usleep(coder->data->time_comp * 1000);

				print_logs(coder->id, "debug", coder->data);
				usleep(coder->data->time_debug * 1000);

				print_logs(coder->id, "refac", coder->data);
				usleep(coder->data->time_refac * 1000);
			}
			else
			{
				pthread_mutex_unlock(coder->left_dongle);
				usleep(100);
				continue;
			}
		}
		else
		{
			usleep(100);
			continue;
		}
	}
	return NULL;
}

int	try_take_dongle(t_dongle *dongle, t_data *data)
{
	pthread_mutex_lock(&dongle->lock);
	if (get_time_ms() - data->start_time >= dongle->cooldown)
	{
		dongle->cooldown = (get_time_ms() - data->start_time) + data->dongle_cooldown;
		pthread_mutex_unlock(&dongle->lock);
		return (1);
	}
	return (0);
}

static	void	unlock_dongles(t_coder *coder)
{
	coder->left_dongle = coder->data->dongle_cooldown;
	coder->right_dongle = coder->data->dongle_cooldown;
	pthread_mutex_unlock(coder->right_dongle);
	pthread_mutex_unlock(coder->left_dongle);
}

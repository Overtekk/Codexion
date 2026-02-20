/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:40:21 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/20 20:39:15 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	*do_action(t_coder *coder, char *action);

void	*coder_thread(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	while (get_simulation(coder->data) == 1 && coder->have_finished == 0)
	{
		if (is_fifo(coder->data))
			scheduler_fifo(coder->data, coder, ADD_QUEUE);
		else
			scheduler_edf_add(coder->data, coder);
		do_action(coder, ACT_COMP);
		if (is_fifo(coder->data))
			scheduler_fifo(coder->data, coder, REMOVE_QUEUE);
		do_action(coder, ACT_DEBUG);
		do_action(coder, ACT_REFAC);
	}
	return (NULL);
}

int	take_dongle(t_coder *coder)
{
	if (try_take_dongle(coder->left_dongle, coder->data) == 0)
	{
		if (coder->right_dongle == NULL)
		{
			pthread_mutex_unlock(&coder->left_dongle->lock);
			return (1);
		}
		if (try_take_dongle(coder->right_dongle, coder->data) == 0)
		{
			print_logs(coder->id, coder->left_dongle->id, ACT_TAKE,
				coder->data);
			print_logs(coder->id, coder->right_dongle->id, ACT_TAKE,
				coder->data);
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

static int	*do_action(t_coder *coder, char *action)
{
	if (get_simulation(coder->data) == 0)
		return (NULL);
	else if (strcmp(action, ACT_COMP) == 0)
	{
		set_burnout(coder);
		print_logs(coder->id, 0, ACT_COMP, coder->data);
		usleep(coder->data->time_comp * 1000);
		coder->code_compiled += 1;
		if (coder->code_compiled >= coder->data->compile_required)
			set_finished(coder);
		release_dongles(coder, coder->data);
		coder->last_compile_start = get_sim_time(coder->data);
	}
	else if (strcmp(action, ACT_DEBUG) == 0)
	{
		print_logs(coder->id, 0, ACT_DEBUG, coder->data);
		usleep(coder->data->time_debug * 1000);
	}
	else if (strcmp(action, ACT_REFAC) == 0)
	{
		print_logs(coder->id, 0, ACT_REFAC, coder->data);
		usleep(coder->data->time_refac * 1000);
	}
	return (0);
}

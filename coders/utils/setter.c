/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:53:16 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/17 12:56:58 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	set_burnout(t_coder *coder)
{
	pthread_mutex_lock(&coder->mutex_burnout);
	coder->time_bournout = get_time_ms();
	pthread_mutex_unlock(&coder->mutex_burnout);
}

void	set_finished(t_coder *coder)
{
	pthread_mutex_lock(&coder->mutex_finish);
	coder->have_finished = 1;
	pthread_mutex_unlock(&coder->mutex_finish);
}

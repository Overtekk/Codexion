/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:03:58 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/11 10:02:11 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_logs(int index, char *action, t_data *data)
{
	long long	time;

	pthread_mutex_lock(&data->mutex_print);
	time = get_time_ms() - data->time;

	if (strcmp(action, "dongle") == 0)
		printf("[%lld] Coder %d has taken a dongle\n", time, index);

	else if (strcmp(action, "compile") == 0)
		printf("[%lld] Coder %d is compiling\n", time, index);

	else if (strcmp(action, "debug") == 0)
		printf("[%lld] Coder %d is debugging\n", time, index);

	else if (strcmp(action, "refac") == 0)
		printf("[%lld] Coder %d is refactoring\n", time, index);

	else if (strcmp(action, "burns_out") == 0)
		printf("[%lld] Coder %d burned out\n", time, index);

	pthread_mutex_unlock(&data->mutex_print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:03:58 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/10 16:20:45 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_logs(long long time, int coder_index, char *action)
{
	if (strcmp(action, "dongle") == 0)
		printf("[%lld] Coder %d has taken a dongle\n", time, coder_index);
	else if (strcmp(action, "compile") == 0)
		printf("[%lld] Coder %d is compiling\n", time, coder_index);
	else if (strcmp(action, "debug") == 0)
		printf("[%lld] Coder %d is debugging\n", time, coder_index);
	else if (strcmp(action, "refac") == 0)
		printf("[%lld] Coder %d is refactoring\n", time, coder_index);
	else if (strcmp(action, "burns_out") == 0)
		printf("[%lld] Coder %d burned out\n", time, coder_index);
}

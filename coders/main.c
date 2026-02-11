/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:16:12 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/11 10:53:43 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 9)
		return (print_error_argc(), 1);
	if (check_arg(argv, &data) == 1)
		return (free_memory(&data), 1);
	debug_print_struct(&data);
	printf("\n");
	init_mutex_for_dongle(&data);
	init_mutex_print(&data);
	init_thread(&data);
	start_simulation(&data);
	join_thread(&data);
	free_memory(&data);
	return (0);
}

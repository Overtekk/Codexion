/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:16:12 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/21 15:27:36 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (argc != 9)
		return (print_error(print_usage(), NULL, &data));
	if (check_arg(&data, argv) == 1)
		return (1);
	init_mutex(&data);
	init_thread(&data);
	join_thread(&data);
	destroy_mutex(&data);
	free_memory(&data);
	return (0);
}

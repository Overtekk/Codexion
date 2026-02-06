/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:29:15 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/06 11:43:02 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_error_argc(void)
{
	fprintf(stderr, "ERROR: Invalid arguments.\nUse ./codexion number_of_"
		"coders time_to_burnout time_to_compile time_to_debug time_to_refactor"
		" number_of_compiles_required dongle_cooldown scheduler\n");
}

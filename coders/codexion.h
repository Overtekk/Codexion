/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:21:24 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/06 15:36:01 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

// -------------- //
//	 INCLUDES	  //
// -------------- //

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

// -------------- //
//	 STRUCTURES	  //
// -------------- //

typedef struct s_data	t_data;

typedef struct s_coder
{
	int			id;
	int			code_compiled;
	long long	time_bournout;
	t_data		*data;
}				t_coder;

typedef struct s_dongle
{
	char		id;
	long long	cooldown;
	t_data		*data;
}				t_dongle;

typedef struct s_data
{
	int			nbr_coders;
	int			nbr_dongle;
	long long	burnout_max;
	long long	time_comp;
	long long	time_debug;
	long long	time_refac;
	long long	dongle_cooldown;
	int			compile_required;
	char		*scheduler;
	t_coder		*coder;
	t_dongle	*dongle;
}				t_data;

// -------------- //
//	 PROTOTYPES	  //
// -------------- //

int		check_arg(char **arg, t_data *data);
int		init_struct(int *value, t_data *data);
void	create_coders_and_dongle(t_data *data);

void	print_error_argc(void);

void	free_memory(t_data *data);

void	debug_print_struct(t_data *data);

#endif

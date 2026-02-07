/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:21:24 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/07 15:53:59 by roandrie         ###   ########.fr       */
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
# include <sys/time.h>

// -------------- //
//	 STRUCTURES	  //
// -------------- //

typedef struct s_data	t_data;

typedef struct s_coder
{
	int				id;
	int				code_compiled;
	long long		time_bournout;
	pthread_t		thread_id;
	pthread_mutex_t	*left_dongle;
	pthread_mutex_t	*right_dongle;
	t_data			*data;
}					t_coder;

typedef struct s_dongle
{
	char			id;
	long long		cooldown;
	pthread_mutex_t	*lock;
	t_data			*data;
}					t_dongle;

typedef struct s_data
{
	int				nbr_coders;
	int				nbr_dongle;
	long long		burnout_max;
	long long		time_comp;
	long long		time_debug;
	long long		time_refac;
	long long		dongle_cooldown;
	int				compile_required;
	char			*scheduler;
	int				simulation_active;
	t_coder			*coder;
	t_dongle		*dongle;
}					t_data;

// -------------- //
//	 PROTOTYPES	  //
// -------------- //

int				check_arg(char **arg, t_data *data);
int				init_thread(t_data *data);
int				start_simulation(t_data *data);
void			*coder_goal(void *arg);

long long		get_time_ms(void);

void			print_error_argc(void);
void			free_memory(t_data *data);

void			debug_print_struct(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:21:24 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/11 15:31:01 by roandrie         ###   ########.fr       */
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
# include <unistd.h>

// -------------- //
//	 STRUCTURES	  //
// -------------- //

typedef struct s_data	t_data;

typedef struct s_queue
{
	t_coder			*coder;
	struct s_queue	*next;
}					t_queue;

typedef struct s_queue_manager
{
	t_queue			*first;
	t_queue			*last;
	pthread_mutex_t	lock;
}					t_queue_manager;

typedef struct s_coder
{
	long long		time_bournout;
	int				id;
	int				code_compiled;
	pthread_t		thread_id;
	pthread_mutex_t	*left_dongle;
	pthread_mutex_t	*right_dongle;
	pthread_mutex_t mutex_burnout;
	t_data			*data;
}					t_coder;

typedef struct s_dongle
{
	long long		cooldown;
	char			id;
	pthread_mutex_t	lock;
	t_data			*data;
}					t_dongle;

typedef struct s_data
{
	long long		burnout_max;
	long long		time_comp;
	long long		time_debug;
	long long		time_refac;
	long long		dongle_cooldown;
	long long		time;
	char			*scheduler;
	int				compile_required;
	int				nbr_coders;
	int				nbr_dongle;
	int				simulation_active;
	t_coder			*coder;
	t_dongle		*dongle;
	t_queue_manager	queue_control;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t mutex_simu;
}					t_data;

// -------------- //
//	 PROTOTYPES	  //
// -------------- //

// Arguments, Malloc, Init structures //
int				check_arg(char **arg, t_data *data);
int				init_struct(int *value, t_data *data);

// Init Threads, Mutex //
void			init_thread(t_data *data);
void			join_thread(t_data *data);
int				init_mutex_for_dongle(t_data *data);
int				init_mutex_print(t_data *data);

// Simulation //
int				start_simulation(t_data *data);
void			*coder_goal(void *arg);

// Getter, Setter //
int				get_simulation(t_data *data);
long long		get_burnout(t_coder *coder);
void			set_burnout(t_coder *coder);

// Logs //
void			print_logs(int index, char *action, t_data *data);

// Functionalities //
long long		get_time_ms(void);
void			print_error_argc(void);
void			free_memory(t_data *data);

// Debug //
void			debug_print_struct(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:21:24 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/11 13:59:24 by roandrie         ###   ########.fr       */
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

}					t_queue;

typedef struct s_coder
{
	int				id;
	int				code_compiled;
	long long		time_bournout;
	pthread_t		thread_id;
	pthread_mutex_t	*left_dongle;
	pthread_mutex_t	*right_dongle;
	pthread_mutex_t mutex_burnout;
	t_data			*data;
}					t_coder;

typedef struct s_dongle
{
	char			id;
	long long		cooldown;
	pthread_mutex_t	lock;
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
	long long		time;
	t_coder			*coder;
	t_dongle		*dongle;
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

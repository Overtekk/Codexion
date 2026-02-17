/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:21:24 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/17 11:36:25 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

// -------------------- //
//		INCLUDES		//
// -------------------- //

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// -------------------- //
//		MACROS			//
// -------------------- //

// Errors message //
# define STR_ERR_MALLOC		"Could not allocate memory.\n"
# define STR_ERR_INV_ARG	"Invalid argument"

// Logs message //
# define LOG_TAKE_DONGLE	"[%lld] Coder %d has taken dongle %c\n"
# define LOG_COMPILING		"[%lld] Coder %d is compiling (%d)\n"
# define LOG_DEBUGGING		"[%lld] Coder %d is debugging\n"
# define LOG_REFACTOR		"[%lld] Coder %d is refactoring\n"
# define LOG_BURNS_OUT		"[%lld] Coder %d burned out\n"
# define LOG_SUCCESS		"All coders have compiled. They can rest... for now"

// Action //
# define ACT_TAKE		"takedongle"
# define ACT_COMP		"compile"
# define ACT_DEBUG		"debug"
# define ACT_REFAC		"refac"
# define ACT_BURNS		"burns_out"
# define REMOVE_QUEUE	"remove_q"
# define ADD_QUEUE		"add_q"

// Max coders //
# define MAX_CODERS 300

// -------------------- //
//		STRUCTURES		//
// -------------------- //

typedef struct s_data			t_data;
typedef struct s_coder			t_coder;
typedef struct s_dongle			t_dongle;
typedef struct s_queue			t_queue;
typedef struct s_queue_manager	t_queue_manager;

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
	pthread_cond_t	cond;
}					t_queue_manager;

typedef struct s_coder
{
	long long		time_bournout;
	int				id;
	int				code_compiled;
	int				have_finished;
	pthread_t		thread_id;
	t_dongle		*left_dongle;
	t_dongle		*right_dongle;
	pthread_mutex_t	mutex_burnout;
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
	long long		start_time;
	char			*scheduler;
	int				compile_required;
	int				nbr_coders;
	int				nbr_dongle;
	int				simulation_active;
	t_coder			*coder;
	t_dongle		*dongle;
	t_queue_manager	queue_control;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_simu;
	pthread_t		monitoring_id;
}					t_data;

// -------------------- //
//		PROTOTYPES		//
// -------------------- //

// Arguments, Malloc, Init structures //
int				check_arg(char **arg, t_data *data);
int				init_struct(int *value, t_data *data);

// Threads, mutex management //
void			init_thread(t_data *data);
void			join_thread(t_data *data);
int				init_mutex_for_dongle(t_data *data);
int				init_mutex_print(t_data *data);
int				add_to_queue(t_queue_manager *manager, t_coder *coder_to_add);
int				remove_from_queue(t_queue_manager *manager);
int				destroy_mutex(t_data *data);

// Simulation //
void			*start_simulation(void *arg);
void			*coder_goal(void *arg);
int				take_dongle(t_coder *coder);
int				try_take_dongle(t_dongle *dongle, t_data *data);
void			reset_dongle_cooldown(t_coder *coder, t_data *data);
int				scheduler_fifo(t_data *data, t_coder *coder, char *action);

// Getter, Setter //
int				get_simulation(t_data *data);
long long		get_burnout(t_coder *coder);
void			set_burnout(t_coder *coder);

// Logs //
void			print_logs(int index, char dongle_id, char *action,
					t_data *data);

// Functionalities //
long long		get_time_ms(void);
long long		get_sim_time(t_data *data);
int				print_error(char *str, char *details, t_data *data);
void			free_memory(t_data *data);
char			*print_usage(void);

// Debug //
void			debug_print_struct(t_data *data);
void			debug_print_queue(t_queue_manager *manager);
void			debug_test_add_queue(t_data *data, t_coder *coder);

#endif

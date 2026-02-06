/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:21:24 by roandrie          #+#    #+#             */
/*   Updated: 2026/02/06 11:59:57 by roandrie         ###   ########.fr       */
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

typedef struct s_dongle
{
	int			number;
	int			cooldown;
}				t_dongle;

typedef struct s_coder
{
	int			number;
	int			time_burnout;
}				t_coder;

typedef struct s_data
{
	t_coder		coder;
	t_dongle	dongle;
	int			time_comp;
	int			time_debug;
	int			time_refac;
	int			compile_required;
	char		*scheduler;
}				t_data;

// -------------- //
//	 PROTOTYPES	  //
// -------------- //

int		check_arg(char **arg);

void	print_error_argc(void);

#endif

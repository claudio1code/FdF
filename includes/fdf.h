/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:41:07 by clados-s          #+#    #+#             */
/*   Updated: 2025/09/30 16:02:38 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

#  define KEY_ESC 65307

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}t_vars;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:21:23 by ywake             #+#    #+#             */
/*   Updated: 2021/06/22 22:56:45 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_H
# define X_H

# define XEV_KEY_PRESS		2
# define XEV_KEY_RELEASE	3
# define XEV_EXPOSE			12
# define XEV_EXIT			17

# define MASK_PRESS			(0L)
# define MASK_RELEASE		(2L)
# define MASK_EXPOSURE		(32768L)
# define MASK_STRUCT_NOTIFY	(131072L)

# ifdef __MACH__

#  define KEY_ESC			53
#  define KEY_Q				12
#  define KEY_W				13
#  define KEY_E				14
#  define KEY_R				15
#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_M				46
#  define KEY_LEFT			123
#  define KEY_RIGHT			124

# else

#  define KEY_ESC			65307
#  define KEY_Q				113
#  define KEY_W				119
#  define KEY_E				101
#  define KEY_R				114
#  define KEY_A				97
#  define KEY_S				115
#  define KEY_D				100
#  define KEY_M				109
#  define KEY_LEFT			65361
#  define KEY_RIGHT			65363

# endif

#endif

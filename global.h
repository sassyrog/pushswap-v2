/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rogerndaba@gmil.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:38:09 by rmdaba            #+#    #+#             */
/*   Updated: 2019/08/21 19:46:09 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <checker.h>

void	normalize_argv(int *ac, char ***av);
void	free_double_arr(void ***arr);
void	build_stacks(t_checker *t_c, char ***av, int ac);

#endif

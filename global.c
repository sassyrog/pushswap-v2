/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rogerndaba@gmil.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:39:20 by rmdaba            #+#    #+#             */
/*   Updated: 2019/09/07 14:38:39 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <global.h>

void	normalize_argv(int *ac, char ***av)
{
	char	**tmp_av;
	char	**split;
	char	*new_av;
	int		i;

	tmp_av = *av;
	new_av = (char *)malloc(65535);
	i = 0;
	while (++i < *ac) {
		new_av = ft_strcat(new_av, " ");
		if (!ft_strncmp(tmp_av[i], "-", 1) && !ft_isdigit(tmp_av[i][1])) {
			continue;
		} else {
			new_av = ft_strcat(new_av, tmp_av[i]);
		}
	}
	*av = ft_strsplit(new_av, ' ');
	tmp_av = *av;
	i = 0;
	while (tmp_av[i])
		i++;
	*ac = i;
	free(new_av);
}


void build_stacks(t_checker *t_c, char ***av, int ac) {
	int		i;
	char	**tmp_av;
	int		val;

	i = -1;
	tmp_av = *av;
	t_c->s_a = (int *)malloc(sizeof(int) * ac);
	t_c->s_b = (int *)malloc(sizeof(int) * ac);
	while (tmp_av[++i])
	{
		val = ft_atoi(tmp_av[i]);
		if (val == 0 && ft_strcmp(tmp_av[i], "0"))
		{
			free_double_arr((void ***)&(*av));
			free(t_c->s_a);
			free(t_c->s_b);
			simple_printf(B_RED"Error\n"RESET);
			exit(EXIT_FAILURE);
		}
		else
			t_c->s_a[i] = val;
	}
	t_c->size = t_c->size_a;
	copy_arr(&t_c->srtd, t_c->s_a, t_c->size_a);
	insertion_sort(&t_c->srtd, t_c->size_a);
}


void	free_double_arr(void ***arr)
{
	char	**tmp_arr;
	int		i;

	tmp_arr = (char **)*arr;
	i = -1;
	while (tmp_arr[++i])
		ft_strdel(&tmp_arr[i]);
	free(tmp_arr);
}

void	insertion_sort(int **array, int n)
{
    int		i;
	int		key;
	int		j;
	int		*arr;

	arr = *array;
	i = -1;
	while (++i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

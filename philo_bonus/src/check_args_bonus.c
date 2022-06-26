/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:57:12 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/26 22:02:01 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers_bonus.h"

void	check_args3(char i)
{
	if (!(i >= '0' && i <= '9'))
		print_err("error\nall arguments must be positive numbers\n");
}

void	check_args2(char **av, int i, int j)
{
	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-')
			print_err("error\nall arguments must be positive numbers\n");
		if (av[i][0] == '+')
			j++;
		if (!av[i][j])
			print_err("error\n");
		while (av[i][j])
		{
			check_args3(av[i][j]);
			j++;
		}
		i++;
	}
}

void	is_not_int(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_atoi(av[i]) || ft_atoi(av[1]) > 200)
			print_err("error\n");
		i++;
	}
	i = 2;
	while (av[i] && i < 5)
	{
		if (ft_atoi(av[i]) < 60)
			print_err("error\n");
		i++;
	}
}

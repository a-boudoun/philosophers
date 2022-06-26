/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:57:12 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/26 22:02:30 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	check_args3(char i)
{
	if (!(i >= '0' && i <= '9'))
	{
		print_err("error\nall arguments must be positive numbers\n");
		return (1);
	}
	return (0);
}

int	check_args2(char **av, int i, int j)
{
	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-')
		{
			print_err("error\nall arguments must be positive numbers\n");
			return (1);
		}
		if (av[i][0] == '+')
			j++;
		if (!av[i][j])
		{
			print_err("error\n");
			return (1);
		}
		while (av[i][j])
		{
			if (check_args3(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_not_int(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_atoi(av[i]) || ft_atoi(av[1]) > 200)
			return (1);
		i++;
	}
	i = 2;
	while (av[i] && i < 5)
	{
		if (ft_atoi(av[i]) < 60)
			return (1);
		i++;
	}
	return (0);
}

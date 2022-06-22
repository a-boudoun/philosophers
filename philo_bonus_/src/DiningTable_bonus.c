/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiningTable_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:40:15 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/22 22:37:08 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	eat(t_philo *ph)
{
	ft_print("is eating", ph->nbr + 1, ph->data);
	ph->last_eat = ft_get_time();
	ph->nbr_eat++;
	ft_usleep((ph->data->time_eat), ft_get_time());
}

void	ft_sleep(t_philo *ph)
{
	ft_print("is sleeping", ph->nbr + 1, ph->data);
	ft_usleep((ph->data->time_sleep), ft_get_time());
}

void	take_forks(t_philo *ph)
{
	sem_wait(ph->data->forks);
	ft_print("is taking a fork", ph->nbr + 1, ph->data);
	sem_wait(ph->data->forks);
	ft_print("is taking a fork", ph->nbr + 1, ph->data);
	eat(ph);
	sem_post(ph->data->forks);
	sem_post(ph->data->forks);
	if (ph->nbr_eat == ph->data->must_eat)
		exit(0);
}

void	ft_actions(t_philo *ph)
{
	if (ph->nbr % 2 == 0)
		ft_usleep(100, ft_get_time());
	while (1)
	{
		take_forks(ph);
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr + 1, ph->data);
		usleep(100);
	}
}

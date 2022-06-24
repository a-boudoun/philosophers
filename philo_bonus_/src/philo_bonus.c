/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:37:16 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/24 22:06:26 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	*end_diner(void *philo)
{
	t_philo	*ph;
	int		i;

	i = -1;
	ph = philo;
	while (!ph->dead)
	{
		sem_wait(ph->eat);
		if (ft_get_time() >= ph->should_die)
		{
			ph->dead = 1;
			usleep(200);
			ft_print_dead("died", ph->nbr + 1, ph);
			while (++i < ph->data->nb_philo)
				sem_post(ph->data->finish);
		}
		sem_post(ph->eat);
		usleep(50);
	}
	return (NULL);
}

void	get_philodata(t_data *data)
{
	int	i;
	int	pid;

	i = -1;
	data->start_time = ft_get_time();
	while (++i < data->nb_philo)
	{
		data->philo[i].should_die = data->start_time + data->time_die;
		data->philo[i].eat = sem_open("eat", O_CREAT, 644, 1);
		data->philo[i].nbr = i;
		data->philo[i].dead = 0;
		data->philo[i].data = data;
		data->philo[i].nbr_eat = 0;
		pid = fork();
		if (pid == 0)
			ft_actions(&(data->philo[i]));
		data->table_id[i] = pid;
	}
}

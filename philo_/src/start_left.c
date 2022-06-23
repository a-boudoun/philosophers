/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:25:40 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/23 19:40:00 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

void	start_left(t_philo *ph)
{
	while (!ph->data->finish)
	{
		take_left_fork(ph);
		if (ph->data->nb_philo == 1)
		{
			ph->data->finish = 1;
			ft_usleep(ph->data->time_die, ft_get_time());
			break ;
		}
		take_right_fork(ph);
		eat(ph);
		pthread_mutex_unlock(&(ph->left_fork));
		pthread_mutex_unlock(ph->right_fork);
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr + 1, ph->data);
	}
}

void	start_right(t_philo *ph)
{
	while (!ph->data->finish)
	{
		take_right_fork(ph);
		if (ph->data->nb_philo == 1)
		{
			ph->data->finish = 1;
			ft_usleep(ph->data->time_die, ft_get_time());
			break ;
		}
		take_left_fork(ph);
		eat(ph);
		pthread_mutex_unlock(ph->right_fork);
		pthread_mutex_unlock(&(ph->left_fork));
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr + 1, ph->data);
	}
}

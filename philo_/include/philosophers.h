/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:44:51 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/22 21:25:00 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <time.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		philo_t;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	int				nbr;
	int				nbr_eat;
	long long		last_eat;
	struct s_data	*data;

}		t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	int				must_eat;
	int				finish;
	int				philo_have_eaten;
	int				start_time;
	t_philo			*philo;
	pthread_mutex_t	print;
}		t_data;

/*****MAIN_FUNCTIONS****/
long long	ft_get_time(void);
void		*end_diner(void *ndata);
void		ft_print(char *messege, int p, t_data *data);
void		ft_destroy(t_data *data);
int			get_data(char **av, t_data *data);
void		get_philodata(t_data *data);
int			check_args(int ac, char **av);
int			ft_atoi(char *str);
void		*ft_actions(void *philo);
void		ft_print_dead(char *messege, int p, t_data *data);
void		ft_usleep(unsigned long time, unsigned long start);
void		print_err(char *message);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:44:51 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/26 21:34:52 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

/******COLORS******/
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define WHT "\x1B[37m"

typedef struct s_philo
{
	sem_t			*eat;
	int				nbr;
	int				nbr_eat;
	long long		should_die;
	int				dead;
	struct s_data	*data;

}		t_philo;

typedef struct s_data
{
	sem_t			*forks;
	sem_t			*print;
	sem_t			*finish;
	int				nb_philo;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	int				must_eat;
	int				philo_have_eaten;
	long long		start_time;
	int				*table_id;
	t_philo			*philo;
}		t_data;

/*****MAIN_FUNCTIONS****/
long long	ft_get_time(void);
void		*end_diner(void *ndata);
void		ft_print(char *messege, int p, t_philo *ph);
void		ft_destroy(t_data *data);
void		get_data(char **av, t_data *data);
void		get_philodata(t_data *data);
void		check_args(int ac, char **av);
int			ft_atoi(char *str);
void		ft_actions(t_philo *ph);
void		ft_print_dead(char *messege, int p, t_philo *ph);
void		ft_usleep(unsigned long time, unsigned long start);
void		print_err(char *message);

/**check args functions**/
void		is_not_int(char **av);
void		check_args2(char **av, int i, int j);
void		check_args3(char i);

#endif

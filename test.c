#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include"philosophers.h"

typedef struct s_test
{
    pthread_mutex_t   left;
    pthread_mutex_t *right;
    pthread_t t;
    int nb;
}   t_test;

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	n;

	s = 1;
	i = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t' || str [i] == '\f'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		n = n * 10 + ((int)str[i] - '0');
		i++;
	}
	return (n * s);
}

void *routine(void *test)
{
    t_test *a; 
   
    a = test;
    if (a->nb % 2 == 0)
        usleep(200);
    while(1)
    {
        pthread_mutex_lock(&(a->left));
        printf("thread %d taking left %d\n", a->nb, a->nb);
        pthread_mutex_lock(a->right);
        printf("thread %d taking right %d\n", a->nb, a->nb + 1);
        usleep(200);
        pthread_mutex_unlock(&(a->left));
        printf("thread %d puting left %d\n", a->nb, a->nb);
        pthread_mutex_unlock(a->right);
        printf("thread %d puting right %d\n", a->nb, a->nb + 1);
        usleep(200);
    }
    return(NULL);
}

int main(int ac, char **av)
{
    t_test  *test;
    int ph;

    (void)ac;
    ph = ft_atoi(av[1]);
    test = malloc(sizeof(t_test) * ph);
    int i = 0;


    while(i < ph)
    {
        pthread_mutex_init(&test[i].left, NULL);
        i++;
    }
    i = 0;
    while(i < ph)
    {
        test[i].nb = i;
         if (i == ph - 1)
           test[i].right = &test[0].left;
        else
            test[i].right = &test[i + 1].left;
        pthread_create(&test[i].t, NULL, &routine, &test[i]);
        i++;
    }
    i = ph;
    while(i)
    {
        pthread_join(test[i].t, NULL);
        i--;
    }
}
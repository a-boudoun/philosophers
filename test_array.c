#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

// int m = 0;
// typedef struct s_test
// {
//     pthread_mutex_t   left;
//     pthread_mutex_t *right;
//     pthread_t t;
//     int nb;
// }   t_test;

    pthread_mutex_t     left[4];
    pthread_mutex_t     right[4];
    pthread_t           t[4];
void *routine(int i)
{
    if (i == 4)
        return (NULL);
    pthread_mutex_lock(&left[i]);
    pthread_mutex_lock(&right[i]);
    printf("starting thread\n");
    printf("ending thread\n");
    pthread_mutex_unlock(&left[i]);
    pthread_mutex_unlock(&right[i]);

}

int main()
{
    //test = malloc(sizeof(t_test) * 4);
    int i = 0;
    while(++i <= 4)
        pthread_mutex_init(&left[i], NULL);
    i = 0;
    while(++i <= 4)
    {
        if (i == 4)
             right[i] = left[1];
        else
             right[i] = left[i + 1];
        pthread_create(&t[i], NULL, &routine, i);
    }
    i = 4;
    while(i)
    {
        pthread_join(&t[i], NULL);
        i--;
    }
    sleep(3);
}
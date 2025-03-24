/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:56:33 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/24 11:54:47 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ---------------------------> mutual exceusion
// usleep, 
// gettimeofday, 
// pthread_create, for create a new thread
// pthread_detach,
// pthread_join,// Wait for the thread to finish and get the result

// pthread_mutex_init  ,
// pthread_mutex_destroy,
// pthread_mutex_lock,
// pthread_mutex_unlock

void    writees(t_philo *philo, int x)
{
    if (x == 0)
        printf("id  %d has taken a fork\n", philo->id);
    if (x == 1)
        printf("%ld ms %d is eating\n",(get_time() - philo->time),philo->id);
    if (x == 2)
        printf("%ld ms %d  is sleeping\n",(get_time() - philo->time), philo->id); 
    if (x == 3)
        printf("%ld ms %d  is thinking\n",(get_time() - philo->time), philo->id);
    if (x == 4)
        printf("%ld ms %d  died\n",(get_time() - philo->time), philo->id);
}

void    *routine(void *av)
{
    t_philo *philo;

    philo = (t_philo *)av;
    philo->fork_left = philo->id;
    philo->fork_right = (philo->id + 1) % philo->number_of_philo;
    if (philo->id % 2 != 0)
        usleep(500);
    fun_eat(philo);
    return (0);
}
void    take_fork(t_philo *philo)
{
    int i;

    i = 0;
    philo->forks = malloc(sizeof(pthread_mutex_t) * philo->number_of_fork);
    if (!philo->forks)
        return ;
    i = 0;
    while (i < philo->number_of_fork) 
    {
        if (pthread_mutex_init(&philo->forks[i], NULL) != 0) 
        return ;
        i++;
    }
}

void    create_threads(t_philo *philo)
{
    int i;
    t_philo *head = NULL;
    t_philo *new_node;
    
    i = 0;
    printf("1\n");
    while (i < philo->number_of_philo)
    {
        new_node = ft_lstnew(philo, i);
        printf("id --> %d\n", new_node->id);
        if (!new_node)
            return ;
        ft_lstadd_back(&head, new_node);
        pthread_create(&new_node->threads, NULL, &routine, new_node);
        i++;
    }
    exit(1);
    t_philo *current = head;
    while (current)
    {
        pthread_join(current->threads, NULL);
        current = current->next;
    }
    i = 0;
    while (i < philo->number_of_fork)
        pthread_mutex_destroy(&philo->forks[i++]);
}

int main(int ac, char **av)
{
    t_philo philo;
    
    check_av(av , ac);
    times(&philo, av);
    take_fork(&philo);
    create_threads(&philo);
}

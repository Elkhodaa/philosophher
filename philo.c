/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:56:33 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/24 13:47:34 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void fun_eat(t_philo *philo)
{   
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(&philo->forks[philo->fork_left]);
        writees(philo, 0);
        pthread_mutex_lock(&philo->forks[philo->fork_right]);
        writees(philo, 0);
    }
    else
    {
        pthread_mutex_lock(&philo->forks[philo->fork_right]);
        writees(philo, 0);
        pthread_mutex_lock(&philo->forks[philo->fork_left]);
        writees(philo, 0);
    }
    writees(philo, 1);
    while ((get_time() - philo->time) < philo->time_to_eat)
        usleep(100);
    philo->time = get_time();
    func_sleep(philo);
    writees(philo, 3);
    pthread_mutex_unlock(&philo->forks[philo->fork_left]);
    pthread_mutex_unlock(&philo->forks[philo->fork_right]);
}

void    *routine(void *av)
{
    t_philo *philo;

    philo = (t_philo *)av;
    philo->fork_left = philo->id;
    philo->fork_right = (philo->id + 1) % philo->number_of_fork;
    if (philo->id % 2 != 0)
        usleep(100);
    fun_eat(philo);
    return (0);
}
void    take_forks(t_philo *philo)
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
    t_philo *current;
    t_philo *new_node;
    
    i = 0;
    while (i < philo->number_of_philo)
    {
        new_node = ft_lstnew(philo, i);
        if (!new_node)
        return ;
        ft_lstadd_back(&head, new_node);
        pthread_create(&new_node->threads, NULL, &routine, new_node);
        i++;
    }
    current = head;
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
    take_forks(&philo);
    create_threads(&philo);
}

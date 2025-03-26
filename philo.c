/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:56:33 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/26 12:26:45 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *av)
{
    t_philo *philo;

    philo = (t_philo *)av;
    if (philo->number_of_philo % 2 != 0)
        usleep(500);
    fun_eat(philo);
    return (0);
}

void    mutex_forks(t_philo *philo)
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
    i = 0;
    while (i < philo->number_of_fork)
        pthread_mutex_destroy(&philo->forks[i++]);
}

void    join_thread(t_philo *head)
{
    t_philo *current;
    current = head;
    while (current)
    {
        if (pthread_join(current->threads, NULL) != 0)
            return ;
        current = current->next;
    }
}

void    create_threads(t_philo *philo)
{
    int i;
    t_philo *head = NULL;
    t_philo *new_node;
    
    i = 0;
    while (i < philo->number_of_philo)
    {
        new_node = ft_lstnew(philo, i);
        if (!new_node)
            return ;
        ft_lstadd_back(&head, new_node);
        pthread_create(&new_node->threads, NULL, routine, new_node);
        i++;
    }
    join_thread(head);
}

int main(int ac, char **av)
{
    t_philo philo;
    
    check_av(av , ac);
    times(&philo, av);
    mutex_forks(&philo);
    create_threads(&philo);
}

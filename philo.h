/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:53:40 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/24 11:22:39 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
# include <limits.h>
#include <sys/time.h>


typedef struct philo
{
    int     id;
    long    time;
    int     number_of_philo;
    int     number_of_fork;
    int     fork_left;
    int     fork_right;
    int     time_to_eat;
    int     time_to_die;
    int     time_to_sleep;
    int     time_to_think;
    pthread_t threads;
    pthread_mutex_t *forks;
    struct philo *next;
    
}t_philo;


typedef struct s_list
{
    t_philo *philo;  
}	t_list;



void	ft_putstr_fd(char *s, int fd);
long	ft_atoi(char *str);
void    check_av(char **av, int ac);
t_philo	*ft_lstnew(t_philo *philo, int i);
int	ft_lstsize(t_philo *lst);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void    writees(t_philo *philo, int x);
long get_time();
void    times(t_philo *philo, char **av);
void    func_sleep(t_philo *philo);
void   fun_eat(t_philo *philo);


#endif
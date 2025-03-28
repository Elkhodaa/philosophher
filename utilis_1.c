/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:54:53 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/28 16:12:08 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(t_philo *philo, int i)
{
	t_philo *new;
	

    new = malloc(sizeof(t_philo));
    if (!new)
		return (NULL);
	new->id = i + 1;
	new->forks = philo->forks;
	new->number_of_fork = philo->number_of_fork;
	new->fork_left = i;
	new->fork_right = (i + 1) % philo->number_of_fork;
	new->thread = 0;
	new->next = NULL;
    return (new);
}
t_philo	*ft_lstlast(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*node;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dongels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:37:16 by khnoman           #+#    #+#             */
/*   Updated: 2026/04/17 14:37:18 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_dongle *create_dongles(t_args *arg){
    if (arg == NULL || arg -> number_of_coders <= 0){
        return NULL;
    }

    int number_dongles;
    t_dongle *arr_dongles;

    int i;
    i = 0;
    number_dongles = arg->number_of_coders;
    arr_dongles = malloc((number_dongles) * sizeof(t_dongle));
    if (!arr_dongles)
    {
        return NULL;
    }

    while (i < number_dongles)
    {
       
       pthread_mutex_init(&arr_dongles[i].mutex, NULL);
       arr_dongles[i].last_used_time = 0;
       i++;
    }

    return arr_dongles;
}


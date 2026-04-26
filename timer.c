/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:17:52 by khnoman           #+#    #+#             */
/*   Updated: 2026/04/25 11:17:57 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

long long time_current(void){
    long long now;
    struct timeval now_t;
    gettimeofday(&now_t, NULL);
    now = (now_t.tv_sec * 1000) + (now_t.tv_usec / 1000);
    return now;
}

void *monitor_check(void *d){
     int i;
     long long now ;
     long long timestamp;
     int number_coder;
     t_data *data;
     data = (t_data *)d;
     number_coder = data->args.number_of_coders;
     while (data->stop == 0)
     {
        i = 0;
        now = time_current();
        while (i < number_coder)
        {
           
            if ( now - data->coders[i].last_compile_time >= data->args.time_to_burnout){
                
                pthread_mutex_lock(&data->print_lock);
                timestamp = now - data->coders[i].data->start_time;
                printf("%lld %d burned out\n",timestamp, data->coders[i].id);
                pthread_mutex_unlock(&data->print_lock);
                data->stop = 1;
                return NULL;
            }
            i++;
        }
     }
    return NULL;
}
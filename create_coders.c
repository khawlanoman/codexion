/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:09:33 by khnoman           #+#    #+#             */
/*   Updated: 2026/04/06 12:09:36 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "head.h"

void *thread_f(void *arg){
    t_coder *coder;

    coder = (t_coder *)arg;

    while(!coder->data->stop){
        if (coder->id % 2 == 0)
        {
            pthread_mutex_lock(&coder->left_dongle->mutex);
            pthread_mutex_lock(&coder->right_dongle->mutex);
        }
        else{
            pthread_mutex_lock(&coder->right_dongle->mutex);
            pthread_mutex_lock(&coder->left_dongle->mutex);
        }
        coder->state = compile;
        printf("%d is %d",coder->id,coder->state);
        sleep(coder->compile_count);

        pthread_mutex_unlock(&coder->left_dongle->mutex);
        pthread_mutex_unlock(&coder->right_dongle->mutex);

    }
    return NULL;
}


t_coder *create_array_coders(t_args *arg){
    int number_coders;
    t_coder *arr_coders;

    number_coders = arg->number_of_coders;
    
    arr_coders = malloc((number_coders) * sizeof(t_coder));
    if (!arr_coders){
        return NULL;
    }
   return arr_coders;
}


void create_coders(t_args *arg){

    if (arg == NULL || arg->number_of_coders <= 0){
        return ;
    }
    int number_coder;
    t_coder *arr_coder;
    int coder;
    number_coder =  arg->number_of_coders;
    pthread_t threads[number_coder];
    int i;
    i = 0;
 
    arr_coder = create_array_coders(arg);
    
    while (i < number_coder)
   {
        threads[i] = i + 1;
       
        coder = pthread_create(&threads[i], NULL, thread_f, NULL);
        arr_coder[i].id  = coder;
        arr_coder[i].thread = threads[i];
        
        i++;
   }
}

void add_dongles_to_coder(t_args *arg, t_coder *coder, t_dongle *dongles){

    if (arg == NULL || coder== NULL || dongles ==NULL || arg->number_of_coders <= 0){
        return ; 
    }
    int number_coder;
    int i;

    number_coder = arg->number_of_coders;
    
    i = 0;

    while(i < number_coder){
        coder[i].left_dongle = &dongles[i];
        coder[i].right_dongle = &dongles[(i +1) % number_coder];
        i++;
    }

}
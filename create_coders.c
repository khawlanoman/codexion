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


t_coder *create_array_coders(t_data *data){
    int number_coders;
    t_coder *arr_coders;
    int i;

    i = 0;
    number_coders = data->args.number_of_coders;
    
    arr_coders = malloc((number_coders) * sizeof(t_coder));
    if (!arr_coders){
        return NULL;
    }
    while (i < number_coders)
    {
        arr_coders[i].id = i+1;
        arr_coders[i].state = 0;
        arr_coders[i].left_dongle = NULL;
        arr_coders[i].right_dongle = NULL;
        arr_coders[i].compile_count = data->args.time_to_compile;
        arr_coders[i].data = data;
        i++;
    }
    
   return arr_coders;
}


void create_coders(t_args *arg, t_coder *arr_coder){

    if (arg == NULL || arg->number_of_coders <= 0){
        return ;
    }
    int number_coder;
   

    number_coder =  arg->number_of_coders;
    int i;
    i = 0;
 
    while (i < number_coder)
   {
        pthread_create(&arr_coder[i].thread, NULL, thread_f, &arr_coder[i]);
        i++;
   }
} 
void add_dongles_to_coder(t_data *data, t_coder *coder, t_dongle *dongles){

    if (data == NULL || coder== NULL || dongles ==NULL || data->args.number_of_coders <= 0){
        return ; 
    }
    int number_coder;
    int i;

    number_coder = data->args.number_of_coders;
    
    i = 0;

    while(i < number_coder){
        coder[i].left_dongle = &dongles[i];
        coder[i].right_dongle = &dongles[(i +1) % number_coder];
        i++;
    }
}
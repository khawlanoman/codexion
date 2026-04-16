/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:18:22 by khnoman           #+#    #+#             */
/*   Updated: 2026/04/06 10:18:28 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
#define HEAD_H


#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    fifo,
    edf
} scheduler_type;

typedef enum{
    compile,
    debug,
    refactor

} state_type;

typedef struct args {
    int number_of_coders;
    time_t time_to_burnout;
    time_t time_to_compile;
    time_t time_to_debug;
    time_t time_to_refactor;
    int number_of_compiles_required;
    time_t dongle_cooldown;
    scheduler_type scheduler;
}t_args;

typedef struct dongle{
    pthread_mutex_t mutex;
    time_t last_used_time;

} t_dongle;

 typedef struct coder{
    int id;
    pthread_t thread;
    t_dongle *left_dongle;
    t_dongle *right_dongle;
    time_t last_compile_time;
    int compile_count;
    state_type statue;
    struct args *config;
} t_coder;

char *check_args(t_args *arg);
char *valid_args(char **argv, int argc);






#endif

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
typedef enum {
    fifo,
    edf
} scheduler_type;

typedef enum{
    compile,
    debug,
    refactor

} state_type;

struct args {
    int number_of_coders;
    time_t time_to_burnout;
    time_t time_to_compile;
    time_t time_to_debug;
    time_t time_to_refactor;
    int number_of_compiles_required;
    time_t dongle_cooldown;
    scheduler_type scheduler;
};

struct dongle{
    pthread_mutex_t mutex;
    time_t last_used_time;

};

struct coder{
    int id;
    pthread_t thread;
    struct dongle *left_dongle;
    struct dongle *right_dongle;
    time_t last_compile_time;
    int compile_count;
    state_type statue;
    struct args *config;
} t;


#endif

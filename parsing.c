/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:26:13 by khnoman           #+#    #+#             */
/*   Updated: 2026/04/15 22:26:16 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "head.h"

char *check_args(struct args arg){
    

    if (arg.number_of_coders< 0)
       return "error: number of coders must be positive";
    if (arg.time_to_burnout< 0)
       return "error: time to burnout must be positive";
    if (arg.time_to_compile< 0)
       return "error: time to compile must be positive";
    if (arg.time_to_debug< 0)
       return "error: time to debug must be positive";
    if (arg.time_to_refactor< 0)
       return "error: time to refector must be positive";
    if (arg.number_of_compiles_required< 0)
       return "error: number of compiles required must be positive";
    
    if (arg.dongle_cooldown < 0)
       return "error: dongle_cooldown must be positive";
    if (strcmp(arg.scheduler,"fifo" ) != 0 && strcmp(arg.scheduler,"edf") !=0)
       return "error: scheduler must be positive";

    return NULL
}
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
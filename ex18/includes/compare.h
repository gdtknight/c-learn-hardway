/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:13:33 by yoshin            #+#    #+#             */
/*   Updated: 2024/10/14 01:32:44 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_H
#define COMPARE_H

#include "utils.h"

typedef int (*compare_cb)(int a, int b);

int *bubble_sort(int *numbers, int count, compare_cb cp);
int sorted_order(int a, int b);
int reverse_order(int a, int b);
int strange_order(int a, int b);

#endif

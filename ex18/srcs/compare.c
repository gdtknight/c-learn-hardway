/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:13:19 by yoshin            #+#    #+#             */
/*   Updated: 2024/10/14 01:23:22 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/compare.h"

int *bubble_sort(int *numbers, int count, compare_cb cp) {
  int temp = 0;
  int i = 0, j = 0;
  int *target = malloc(count * sizeof(int));

  if (!target)
    die("Memory error.");

  memcpy(target, numbers, count * sizeof(int));

  for (i = 0; i < count; i++) {
    for (j = 0; j < count - 1; j++) {
      if (cp(target[j], target[j + 1]) > 0) {
        temp = target[j + 1];
        target[j + 1] = target[j];
        target[j] = temp;
      }
    }
  }

  return (target);
}

int sorted_order(int a, int b) { return (a - b); }

int reverse_order(int a, int b) { return (b - a); }

int strange_order(int a, int b) {
  if (a == 0 || b == 0) {
    return (0);
  } else {
    return (a % b);
  }
}

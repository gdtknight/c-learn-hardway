/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:22:37 by yoshin            #+#    #+#             */
/*   Updated: 2024/10/14 01:24:18 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/compare.h"

void test_sorting(int *numbers, int count, compare_cb cmp) {
  int i = 0;
  int *sorted = bubble_sort(numbers, count, cmp);

  if (!sorted)
    die("Failed to sort as requested.");

  for (i = 0; i < count; i++) {
    printf("%d ", sorted[i]);
  }
  printf("\n");

  free(sorted);
}

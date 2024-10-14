/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:26:49 by yoshin            #+#    #+#             */
/*   Updated: 2024/10/15 00:29:08 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDRESS_H
#define ADDRESS_H

#include <stdio.h>

#define MAX_DATA 512

typedef struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
} t_address;

void print_address(struct Address *addr);

#endif

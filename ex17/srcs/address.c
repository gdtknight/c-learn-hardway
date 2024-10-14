/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:28:28 by yoshin            #+#    #+#             */
/*   Updated: 2024/10/15 00:28:52 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/address.h"

void print_address(struct Address *addr) {
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

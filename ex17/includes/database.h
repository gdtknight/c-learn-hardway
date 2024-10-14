/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:43:22 by yoshin            #+#    #+#             */
/*   Updated: 2024/10/15 00:28:05 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_H
#define DATABASE_H

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "address.h"

#define MAX_ROWS 100

typedef struct Database {
  struct Address rows[MAX_ROWS];
} t_database;

typedef struct Connection {
  FILE *file;
  struct Database *db;
} t_connection;

void create_database(t_connection *conn);
void delete_database(t_connection *conn, int id);
void load_database(t_connection *conn);
void close_database(t_connection *conn);
void write_database(t_connection *conn);
void get_database(t_connection *conn, int id);
void list_database(t_connection *conn);
t_connection *open_database(const char *filename, char mode);
void set_database(t_connection *conn, int id, const char *name,
                  const char *email);
#endif

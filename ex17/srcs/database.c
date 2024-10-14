/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:44:45 by yoshin            #+#    #+#             */
/*   Updated: 2024/10/15 00:30:55 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/database.h"
#include "../includes/address.h"
#include "../includes/utils.h"

void load_database(t_connection *conn) {
  int rc = fread(conn->db, sizeof(t_database), 1, conn->file);
  if (rc != 1)
    die("Failed to load database.");
}

t_connection *open_database(const char *filename, char mode) {
  t_connection *conn = malloc(sizeof(t_connection));
  if (!conn)
    die("Memory error");

  conn->db = malloc(sizeof(t_database));
  if (!conn->db)
    die("Memory error");

  if (mode == 'c') {
    conn->file = fopen(filename, "w");
  } else {
    conn->file = fopen(filename, "r+");

    if (conn->file) {
      load_database(conn);
    }
  }

  if (!conn->file)
    die("Failed to open the file");

  return conn;
}

void close_database(t_connection *conn) {
  if (conn) {
    if (conn->file)
      fclose(conn->file);
    if (conn->db)
      free(conn->db);
    free(conn);
  }
}

void Database_write(t_connection *conn) {
  rewind(conn->file);

  int rc = fwrite(conn->db, sizeof(t_database), 1, conn->file);
  if (rc != 1)
    die("Failed to write database.");

  rc = fflush(conn->file);
  if (rc == -1)
    die("Cannot flush database.");
}

void Database_create(t_connection *conn) {
  int i = 0;

  for (i = 0; i < MAX_ROWS; i++) {
    // 초기화 용도 프로토타입
    struct Address addr = {.id = i, .set = 0};
    conn->db->rows[i] = addr;
  }
}

void set_database(t_connection *conn, int id, const char *name,
                  const char *email) {
  struct Address *addr = &conn->db->rows[id];
  if (addr->set)
    die("Already set, delete it first");

  addr->set = 1;
  // 경고 :  버그 .  "프로그램 깨뜨리기"  섹션 읽고 고치기
  char *res = strncpy(addr->name, name, MAX_DATA);
  //  strncpy 버그를 보여줌
  if (!res)
    die("Name copy failed");

  res = strncpy(addr->email, email, MAX_DATA);
  if (!res)
    die("Email copy failed");
}

void get_database(t_connection *conn, int id) {
  struct Address *addr = &conn->db->rows[id];

  if (addr->set) {
    print_address(addr);
  } else {
    die("ID is not set");
  }
}

void delete_database(t_connection *conn, int id) {
  struct Address addr = {.id = id, .set = 0};
  conn->db->rows[id] = addr;
}

void list_database(t_connection *conn) {
  t_database *db = conn->db;

  for (int i = 0; i < MAX_ROWS; i++) {
    struct Address *cur = &db->rows[i];

    if (cur->set) {
      print_address(cur);
    }
  }
}

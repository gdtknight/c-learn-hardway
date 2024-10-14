/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:42:51 by yoshin            #+#    #+#             */
/*   Updated: 2024/10/15 00:30:25 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int main(int argc, char *argv[]) {
  if (argc < 3)
    die("USAGE: ex17 <dbfile> <action> [action params]");

  char *filename = argv[1];
  char action = argv[2][0];

  t_connection *conn = open_database(filename, action);

  int id = 0;
  if (argc > 3)
    id = atoi(argv[3]);
  if (id >= MAX_ROWS)
    die("There's not that many records.");

  switch (action) {
  case 'c':
    create_database(conn);
    write_database(conn);
    break;

  case 'g':
    if (argc != 4)
      die("Need an id to get");

    get_database(conn, id);
    break;

  case 's':
    if (argc != 6)
      die("Need id, name, email to set");

    set_database(conn, id, argv[4], argv[5]);
    write_database(conn);
    break;

  case 'd':
    if (argc != 4)
      die("Need id to delete");

    delete_database(conn, id);
    write_database(conn);
    break;

  case 'l':
    list_database(conn);
    break;

  default:
    die("Invalid action: c=create, g=get, s=set, d=del, l=list");
  }

  close_database(conn);

  return (0);
}

#include "main.h"

void add_last(list_t **head, char *str);

list_t *create_linkedlist_from_path_directory(char **directories)
{
  list_t *list = NULL;
  int i;

  list = malloc(sizeof(list_t));
  if (list == NULL)
    return (NULL);

  for (i = 0; directories[i]; i++)
  {
    add_last(&list, directories[i]);
  }

  return (list);
}

void _print_linkedlist(list_t *node)
{
  list_t *tmp;

  while (node != NULL)
  {
    if (node->data)
      printf("%s -> ", node->data);

    tmp = node->next;

    free(node);

    node = tmp;
  }
}

void add_last(list_t **head, char *str)
{
  list_t *new;
  list_t *last;

  new = malloc(sizeof(list_t));
  if (new == NULL)
    exit(-1);

  new->data = str;
  new->next = NULL;

  if (*head == NULL)
  {
    *head = new;
  }
  else
  {
    last = *head;

    while (last->next != NULL)
      last = last->next;

    last->next = new;
  }
}
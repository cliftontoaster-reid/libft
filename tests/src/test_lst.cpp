// filepath: /home/cliftontr/Documents/42/libft/tests/src/test_lst.cpp
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliftontr <cliftontr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:25:00 by cliftontr         #+#    #+#             */
/*   Updated: 2025/02/11 00:25:00 by cliftontr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include <stdlib.h>
#include <string.h>

extern "C"
{
#include "libft.h"
}

static void del(void *content)
{
  free(content);
}

static void nodel(void *content)
{
  (void)content;
}

static void iter_increment(void *content)
{
  if (content)
    *((int *)content) += 1;
}

static void *map_double(void *content)
{
  int *new_val = (int *)malloc(sizeof(int));
  if (new_val)
    *new_val = *((int *)content) * 2;
  return new_val;
}

void test_ft_lstnew(void)
{
  int value = 42;
  t_list *node = ft_lstnew(&value);
  CU_ASSERT_PTR_NOT_NULL(node);
  if (node)
  {
    CU_ASSERT_PTR_EQUAL(node->content, &value);
    CU_ASSERT_PTR_NULL(node->next);
    ft_lstclear(&node, nodel);
  }
}

void test_ft_lstadd_front(void)
{
  int values[3] = {1, 2, 3};
  t_list *list = NULL;

  t_list *node1 = ft_lstnew(&values[0]);
  ft_lstadd_front(&list, node1);
  CU_ASSERT_PTR_EQUAL(list, node1);

  t_list *node2 = ft_lstnew(&values[1]);
  ft_lstadd_front(&list, node2);
  CU_ASSERT_PTR_EQUAL(list, node2);
  CU_ASSERT_PTR_EQUAL(list->next, node1);

  t_list *node3 = ft_lstnew(&values[2]);
  ft_lstadd_front(&list, node3);
  CU_ASSERT_PTR_EQUAL(list, node3);
  CU_ASSERT_PTR_EQUAL(list->next, node2);

  ft_lstclear(&list, nodel);
  CU_ASSERT_PTR_NULL(list);
}

void test_ft_lstadd_back(void)
{
  int values[3] = {10, 20, 30};
  t_list *list = NULL;

  t_list *node1 = ft_lstnew(&values[0]);
  ft_lstadd_back(&list, node1);
  CU_ASSERT_PTR_EQUAL(list, node1);

  t_list *node2 = ft_lstnew(&values[1]);
  ft_lstadd_back(&list, node2);
  CU_ASSERT_PTR_EQUAL(node1->next, node2);

  t_list *node3 = ft_lstnew(&values[2]);
  ft_lstadd_back(&list, node3);
  CU_ASSERT_PTR_EQUAL(node2->next, node3);
  CU_ASSERT_PTR_NULL(node3->next);

  ft_lstclear(&list, nodel);
  CU_ASSERT_PTR_NULL(list);
}

void test_ft_lstsize(void)
{
  t_list *list = NULL;
  CU_ASSERT_EQUAL(ft_lstsize(list), 0);

  int values[5] = {5, 6, 7, 8, 9};
  for (int i = 0; i < 5; i++)
  {
    t_list *node = ft_lstnew(&values[i]);
    ft_lstadd_back(&list, node);
  }
  CU_ASSERT_EQUAL(ft_lstsize(list), 5);

  ft_lstclear(&list, nodel);
  CU_ASSERT_PTR_NULL(list);
}

void test_ft_lstlast(void)
{
  t_list *list = NULL;
  CU_ASSERT_PTR_NULL(ft_lstlast(list));

  int values[3] = {100, 200, 300};
  for (int i = 0; i < 3; i++)
  {
    t_list *node = ft_lstnew(&values[i]);
    ft_lstadd_back(&list, node);
  }
  t_list *last = ft_lstlast(list);
  CU_ASSERT_PTR_NOT_NULL(last);
  if (last)
    CU_ASSERT_PTR_EQUAL(last->content, &values[2]);

  ft_lstclear(&list, nodel);
  CU_ASSERT_PTR_NULL(list);
}

void test_ft_lstiter(void)
{
  int init_values[3] = {1, 2, 3};
  t_list *list = NULL;
  for (int i = 0; i < 3; i++)
  {
    int *num = (int *)malloc(sizeof(int));
    *num = init_values[i];
    t_list *node = ft_lstnew(num);
    ft_lstadd_back(&list, node);
  }

  ft_lstiter(list, iter_increment);

  t_list *cur = list;
  int expected = 2;
  while (cur)
  {
    CU_ASSERT_EQUAL(*((int *)cur->content), expected);
    expected++;
    cur = cur->next;
  }

  ft_lstclear(&list, del);
  CU_ASSERT_PTR_NULL(list);
}

void test_ft_lstmap(void)
{
  int init_values[3] = {4, 5, 6};
  t_list *list = NULL;
  for (int i = 0; i < 3; i++)
  {
    int *num = (int *)malloc(sizeof(int));
    *num = init_values[i];
    t_list *node = ft_lstnew(num);
    ft_lstadd_back(&list, node);
  }

  t_list *new_list = ft_lstmap(list, map_double, del);
  CU_ASSERT_PTR_NOT_NULL(new_list);

  t_list *cur_old = list;
  t_list *cur_new = new_list;
  while (cur_old && cur_new)
  {
    CU_ASSERT_NOT_EQUAL(cur_old->content, cur_new->content);
    CU_ASSERT_EQUAL(*((int *)cur_new->content), *((int *)cur_old->content) * 2);
    cur_old = cur_old->next;
    cur_new = cur_new->next;
  }

  ft_lstclear(&list, del);
  ft_lstclear(&new_list, del);
}

void test_ft_lstclear(void)
{
  int init_values[3] = {7, 8, 9};
  t_list *list = NULL;
  for (int i = 0; i < 3; i++)
  {
    int *num = (int *)malloc(sizeof(int));
    *num = init_values[i];
    t_list *node = ft_lstnew(num);
    ft_lstadd_back(&list, node);
  }
  ft_lstclear(&list, del);
  CU_ASSERT_PTR_NULL(list);
}

void test_ft_lstdelone(void)
{
  int *x1 = (int *)malloc(sizeof(int));
  int *x2 = (int *)malloc(sizeof(int));
  *x1 = 123;
  *x2 = 456;
  t_list *node1 = ft_lstnew(x1);
  t_list *node2 = ft_lstnew(x2);
  CU_ASSERT_PTR_NOT_NULL(node1);
  CU_ASSERT_PTR_NOT_NULL(node2);

  ft_lstadd_back(&node1, node2);
  // Delete the second node
  ft_lstdelone(node2, del);
  // Finally delete the first node
  ft_lstdelone(node1, del);
  CU_PASS("Deleted multiple nodes without crashes");
}

void test_lst(void)
{
  CU_pSuite suite = CU_add_suite("lst", NULL, NULL);

  CU_add_test(suite, "ft_lstnew", test_ft_lstnew);
  CU_add_test(suite, "ft_lstadd_front", test_ft_lstadd_front);
  CU_add_test(suite, "ft_lstadd_back", test_ft_lstadd_back);
  CU_add_test(suite, "ft_lstsize", test_ft_lstsize);
  CU_add_test(suite, "ft_lstlast", test_ft_lstlast);
  CU_add_test(suite, "ft_lstiter", test_ft_lstiter);
  CU_add_test(suite, "ft_lstmap", test_ft_lstmap);
  CU_add_test(suite, "ft_lstclear", test_ft_lstclear);
  CU_add_test(suite, "ft_lstdelone", test_ft_lstdelone);
}
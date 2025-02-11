/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:45:55 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/11 00:50:14 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include <unistd.h>
#include <string.h>

extern "C"
{
  int ft_putchar_fd(char c, int fd);
  int ft_putstr_fd(char *s, int fd);
  int ft_putendl_fd(char *s, int fd);
  int ft_putnbr_fd(int n, int fd);
}

static void test_ft_putchar_fd(void)
{
  int pipefd[2];
  CU_ASSERT_EQUAL(pipe(pipefd), 0);

  ft_putchar_fd('A', pipefd[1]);
  close(pipefd[1]);

  char buffer[2] = {0};
  CU_ASSERT_EQUAL(read(pipefd[0], buffer, 1), 1);
  close(pipefd[0]);

  CU_ASSERT_STRING_EQUAL(buffer, "A");
}

static void test_ft_putstr_fd(void)
{
  int pipefd[2];
  CU_ASSERT_EQUAL(pipe(pipefd), 0);

  ft_putstr_fd((char *)"Hello", pipefd[1]);
  close(pipefd[1]);

  char buffer[6] = {0};
  CU_ASSERT_EQUAL(read(pipefd[0], buffer, 5), 5);
  close(pipefd[0]);

  CU_ASSERT_STRING_EQUAL(buffer, "Hello");
}

static void test_ft_putendl_fd(void)
{
  int pipefd[2];
  CU_ASSERT_EQUAL(pipe(pipefd), 0);

  ft_putendl_fd((char *)"World", pipefd[1]);
  close(pipefd[1]);

  char buffer[7] = {0};
  CU_ASSERT_EQUAL(read(pipefd[0], buffer, 6), 6);
  close(pipefd[0]);

  CU_ASSERT_STRING_EQUAL(buffer, "World\n");
}

static void test_ft_putnbr_fd(void)
{
  int pipefd[2];
  CU_ASSERT_EQUAL(pipe(pipefd), 0);

  ft_putnbr_fd(42, pipefd[1]);
  close(pipefd[1]);

  char buffer[16] = {0};
  ssize_t n = read(pipefd[0], buffer, 15);
  CU_ASSERT(n > 0);
  buffer[n] = '\0';
  close(pipefd[0]);

  CU_ASSERT_STRING_EQUAL(buffer, "42");
}

void test_fd(void)
{
  CU_pSuite suite = CU_add_suite("file_descriptor_functions", NULL, NULL);
  CU_add_test(suite, "ft_putchar_fd", test_ft_putchar_fd);
  CU_add_test(suite, "ft_putstr_fd", test_ft_putstr_fd);
  CU_add_test(suite, "ft_putendl_fd", test_ft_putendl_fd);
  CU_add_test(suite, "ft_putnbr_fd", test_ft_putnbr_fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c_int.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:03:58 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/11 00:06:31 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include <climits>

extern "C"
{
  int ft_atoi(const char *nptr);
  int ft_ciswhite(char c);
  char *ft_itoa(int n);
}

void test_ciswhite(void)
{
  struct test
  {
    char c;
    int expected;
  };

  test cases[] = {
      {' ', 1},
      {'\t', 1},
      {'\n', 1},
      {'\v', 1},
      {'\f', 1},
      {'\r', 1},
      {'a', 0},
      {'0', 0}};
  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    CU_ASSERT_EQUAL(ft_ciswhite(cases[i].c), cases[i].expected);
  }
}

void test_atoi(void)
{
  struct test
  {
    const char *nptr;
    int expected;
  };

  test cases[] = {
      {"42", 42},
      {"   42", 42},
      {"-42", -42},
      {"0", 0},
      {"+42", 42},
      {"   -0", 0},
      {"", 0},
      {"  ", 0},
      {"abc", 0},
      {"-2147483648", INT_MIN},
      {"2147483647", INT_MAX},
  };

  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    CU_ASSERT_EQUAL(ft_atoi(cases[i].nptr), cases[i].expected);
  }
}

void test_itoa(void)
{
  struct test
  {
    int n;
    const char *expected;
  };

  test cases[] = {
      {42, "42"},
      {-42, "-42"},
      {0, "0"},
      {INT_MAX, "2147483647"},
      {INT_MIN, "-2147483648"},
  };

  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    char *res = ft_itoa(cases[i].n);
    CU_ASSERT_STRING_EQUAL(res, cases[i].expected);
    free(res);
  }
}

void test_c_int(void)
{
  CU_pSuite suite = CU_add_suite("c_int", NULL, NULL);

  CU_add_test(suite, "ft_atoi", test_atoi);
  CU_add_test(suite, "ft_ciswhite", test_ciswhite);
  CU_add_test(suite, "ft_itoa", test_itoa);
}
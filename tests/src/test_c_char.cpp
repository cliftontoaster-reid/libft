/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c_char.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:50:20 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/11 00:03:35 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

extern "C"
{
  int ft_isalnum(int c);
  int ft_isalpha(int c);
  int ft_isascii(int c);
  int ft_isdigit(int c);
  int ft_isprint(int c);
  int ft_tolower(int c);
  int ft_toupper(int c);
}

void test_ft_isalnum(void)
{
  struct test
  {
    int c;
    int expected;
  };

  test cases[] = {
      {'a', 1},
      {'z', 1},
      {'A', 1},
      {'Z', 1},
      {'0', 1},
      {'9', 1},
      {' ', 0},
      {'\n', 0},
      {'\t', 0},
      {'!', 0},
      {'~', 0},
      {0, 0}};
  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    CU_ASSERT_EQUAL(ft_isalnum(cases[i].c), cases[i].expected);
  }
}

void test_ft_isalpha(void)
{
  struct test
  {
    int c;
    int expected;
  };

  test cases[] = {
      {'a', 1},
      {'z', 1},
      {'A', 1},
      {'Z', 1},
      {'0', 0},
      {'9', 0},
      {' ', 0},
      {'\n', 0},
      {'\t', 0},
      {'!', 0},
      {'~', 0},
      {0, 0}};
  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    CU_ASSERT_EQUAL(ft_isalpha(cases[i].c), cases[i].expected);
  }
}

void test_ft_isascii(void)
{
  struct test
  {
    int c;
    int expected;
  };

  test cases[] = {
      {0, 1},
      {127, 1},
      {128, 0},
      {255, 0},
      {256, 0},
      {1000, 0},
      {-1, 0},
      {-1000, 0}};
  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    CU_ASSERT_EQUAL(ft_isascii(cases[i].c), cases[i].expected);
  }
}

void test_ft_isdigit(void)
{
  struct test
  {
    int c;
    int expected;
  };

  test cases[] = {
      {'0', 1},
      {'9', 1},
      {'a', 0},
      {'z', 0},
      {'A', 0},
      {'Z', 0},
      {' ', 0},
      {'\n', 0},
      {'\t', 0},
      {'!', 0},
      {'~', 0},
      {0, 0}};
  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    CU_ASSERT_EQUAL(ft_isdigit(cases[i].c), cases[i].expected);
  }
}

void test_ft_isprint(void)
{
  struct test
  {
    int c;
    int expected;
  };

  test cases[] = {
      {' ', 1},
      {'~', 1},
      {'\n', 0},
      {'\t', 0},
      {0, 0},
      {127, 0},
      {128, 0},
      {255, 0},
      {256, 0},
      {1000, 0},
      {-1, 0},
      {-1000, 0}};
  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    CU_ASSERT_EQUAL(ft_isprint(cases[i].c), cases[i].expected);
  }
}

void test_ft_tolower(void)
{
  struct test
  {
    int c;
    int expected;
  };

  test cases[] = {
      {'a', 'a'},
      {'z', 'z'},
      {'A', 'a'},
      {'Z', 'z'},
      {'0', '0'},
      {'9', '9'},
      {' ', ' '},
      {'\n', '\n'},
      {'\t', '\t'},
      {'!', '!'},
      {'~', '~'},
      {0, 0}};
  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    CU_ASSERT_EQUAL(ft_tolower(cases[i].c), cases[i].expected);
  }
}

void test_ft_toupper(void)
{
  struct test
  {
    int c;
    int expected;
  };

  test cases[] = {
      {'a', 'A'},
      {'z', 'Z'},
      {'A', 'A'},
      {'Z', 'Z'},
      {'0', '0'},
      {'9', '9'},
      {' ', ' '},
      {'\n', '\n'},
      {'\t', '\t'},
      {'!', '!'},
      {'~', '~'},
      {0, 0}};
  int numCases = sizeof(cases) / sizeof(test);
  for (int i = 0; i < numCases; i++)
  {
    CU_ASSERT_EQUAL(ft_toupper(cases[i].c), cases[i].expected);
  }
}

void test_c_char(void)
{
  CU_pSuite suite = CU_add_suite("c_chars", NULL, NULL);

  CU_add_test(suite, "ft_isalnum", test_ft_isalnum);
  CU_add_test(suite, "ft_isalpha", test_ft_isalpha);
  CU_add_test(suite, "ft_isascii", test_ft_isascii);
  CU_add_test(suite, "ft_isdigit", test_ft_isdigit);
  CU_add_test(suite, "ft_isprint", test_ft_isprint);
  CU_add_test(suite, "ft_tolower", test_ft_tolower);
  CU_add_test(suite, "ft_toupper", test_ft_toupper);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:53:49 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/11 00:03:27 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

extern "C"
{
  void *ft_memset(void *b, int c, size_t len);
  void *ft_memcpy(void *dst, const void *src, size_t n);
  void *ft_memmove(void *dst, const void *src, size_t len);
  void *ft_memchr(const void *s, int c, size_t n);
  int ft_memcmp(const void *s1, const void *s2, size_t n);
  void *ft_calloc(size_t count, size_t size);
  void ft_bzero(void *s, int n);
}

void test_memset(void)
{
  char test[11] = "aaaaaaaaaa";

  ft_memset(test, 'b', 6);
  CU_ASSERT_STRING_EQUAL(test, "bbbbbbaaaa");

  ft_memset(test, 'c', 0);
  CU_ASSERT_STRING_EQUAL(test, "bbbbbbaaaa");

  ft_memset(test, 'd', 10);
  CU_ASSERT_STRING_EQUAL(test, "dddddddddd");
}

void test_memcpy(void)
{
  char src[11] = "aaaaaaaaaa";
  char dst[11] = "bbbbbbbbbb";

  ft_memcpy(dst, src, 5);
  CU_ASSERT_STRING_EQUAL(dst, "aaaaabbbbb");

  ft_memcpy(dst, src, 0);
  CU_ASSERT_STRING_EQUAL(dst, "aaaaabbbbb");

  ft_memcpy(dst, src, 10);
  CU_ASSERT_STRING_EQUAL(dst, "aaaaaaaaaa");
}

void test_memmove(void)
{
  char src[11] = "aaaaaaaaaa";
  char dst[11] = "bbbbbbbbbb";

  ft_memmove(dst, src, 5);
  CU_ASSERT_STRING_EQUAL(dst, "aaaaabbbbb");

  ft_memmove(dst, src, 0);
  CU_ASSERT_STRING_EQUAL(dst, "aaaaabbbbb");

  ft_memmove(dst, src, 10);
  CU_ASSERT_STRING_EQUAL(dst, "aaaaaaaaaa");
}

void test_memchr(void)
{
  char test[11] = "aaaaaaaaaa";

  CU_ASSERT_PTR_EQUAL(ft_memchr(test, 'b', 10), NULL);
  CU_ASSERT_PTR_EQUAL(ft_memchr(test, 'a', 10), test);
  CU_ASSERT_PTR_EQUAL(ft_memchr(test, 'a', 0), NULL);
}

void test_memcmp(void)
{
  char test1[11] = "aaaaaaaaaa";
  char test2[11] = "aaaaaaaaaa";

  CU_ASSERT_EQUAL(ft_memcmp(test1, test2, 10), 0);
  test2[0] = 'b';
  CU_ASSERT_EQUAL(ft_memcmp(test1, test2, 10), -1);
  test2[0] = 'a';
  test1[0] = 'b';
  CU_ASSERT_EQUAL(ft_memcmp(test1, test2, 10), 1);
}

void test_calloc(void)
{
  // Normal allocation: allocate 10 ints and check that all are zeroed out.
  int *arr = (int *)ft_calloc(10, sizeof(int));
  CU_ASSERT_PTR_NOT_NULL(arr);
  if (arr)
  {
    for (size_t i = 0; i < 10; i++)
      CU_ASSERT_EQUAL(arr[i], 0);
    free(arr);
  }

  // Allocation of zero elements. The returned pointer can be NULL or non-NULL; both behaviors are valid.
  int *arr_zero = (int *)ft_calloc(0, sizeof(int));
  if (arr_zero)
    free(arr_zero);
  else
    CU_PASS("ft_calloc returned NULL for zero size allocation");

  // Test with huge values to simulate an overflow during multiplication.
  size_t huge_count = (size_t)-1;
  int *arr_overflow = (int *)ft_calloc(huge_count, sizeof(int));
  CU_ASSERT_PTR_NULL(arr_overflow);
}

void test_bzero(void)
{
  char test[11] = "aaaaaaaaaa";

  ft_bzero(test, 5);
  CU_ASSERT_STRING_EQUAL(test, "\0\0\0\0\0aaaaa");

  ft_bzero(test, 0);
  CU_ASSERT_STRING_EQUAL(test, "\0\0\0\0\0aaaaa");

  ft_bzero(test, 10);
  CU_ASSERT_STRING_EQUAL(test, "\0\0\0\0\0\0\0\0\0\0");
}

void test_mem(void)
{
  CU_pSuite suite = CU_add_suite("mem", NULL, NULL);
  CU_add_test(suite, "ft_memset", test_memset);
  CU_add_test(suite, "ft_memcpy", test_memcpy);
  CU_add_test(suite, "ft_memmove", test_memmove);
  CU_add_test(suite, "ft_memchr", test_memchr);
  CU_add_test(suite, "ft_memcmp", test_memcmp);
  CU_add_test(suite, "ft_calloc", test_calloc);
  CU_add_test(suite, "ft_bzero", test_bzero);
}

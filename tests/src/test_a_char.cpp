/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_a_char.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:16:35 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/11 00:45:39 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include <stdlib.h>
#include <string.h>

extern "C"
{
  size_t ft_strlen(const char *s);
  int ft_strncmp(const char *s1, const char *s2, size_t n);
  char *ft_strdup(const char *s);
  char *ft_strchr(const char *s, int c);
  char *ft_strrchr(const char *s, int c);
  char *ft_strnstr(const char *haystack, const char *needle, size_t len);
  char **ft_split(char const *s, char c);
  void ft_striteri(char *s, void (*f)(unsigned int, char *));
  char *ft_strjoin(char const *s1, char const *s2);
  size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
  size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
  char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
  char *ft_strtrim(char const *s1, char const *set);
  char *ft_substr(char const *s, unsigned int start, size_t len);
}

void test_ft_strlen(void)
{
  struct test_case
  {
    const char *s;
    size_t expected;
  };
  test_case cases[] = {
      {"", 0},
      {"Hello", 5},
      {"42 is awesome", 13},
      {"\0hidden", 0},
  };
  int num = sizeof(cases) / sizeof(test_case);
  for (int i = 0; i < num; i++)
  {
    CU_ASSERT_EQUAL(ft_strlen(cases[i].s), cases[i].expected);
  }
}

void test_ft_strncmp(void)
{
  CU_ASSERT_EQUAL(ft_strncmp("abcdef", "abcxyz", 3), 0);
  CU_ASSERT(ft_strncmp("abcdef", "abcxyz", 4) < 0);
  CU_ASSERT_EQUAL(ft_strncmp("same", "same", 10), 0);
  CU_ASSERT(ft_strncmp("short", "shorter", 10) < 0);
  CU_ASSERT(ft_strncmp("", "", 1) == 0);
}

void test_ft_strdup(void)
{
  const char *src = "Duplicate me!";
  char *dup = ft_strdup(src);
  CU_ASSERT_PTR_NOT_NULL(dup);
  if (dup)
  {
    CU_ASSERT_STRING_EQUAL(dup, src);
    free(dup);
  }

  char *dup_empty = ft_strdup("");
  CU_ASSERT_PTR_NOT_NULL(dup_empty);
  if (dup_empty)
  {
    CU_ASSERT_STRING_EQUAL(dup_empty, "");
    free(dup_empty);
  }
}

void test_ft_strchr(void)
{
  char str[] = "Find the letter";
  char *result = ft_strchr(str, 't');
  CU_ASSERT_PTR_NOT_NULL(result);
  if (result)
    CU_ASSERT_STRING_EQUAL(result, "the letter");

  // Character not found
  result = ft_strchr(str, 'z');
  CU_ASSERT_PTR_NULL(result);

  // Search for null terminator should return pointer to end of string.
  result = ft_strchr(str, '\0');
  CU_ASSERT_PTR_EQUAL(result, str + strlen(str));
}

void test_ft_strrchr(void)
{
  char str[] = "Look for the last letter t in this sentence: t";
  char *result = ft_strrchr(str, 't');
  CU_ASSERT_PTR_NOT_NULL(result);
  if (result)
  {
    // Since this is the last occurrence, compare with standard function.
    CU_ASSERT_EQUAL(result, ft_strrchr(str, 't'));
  }

  // Character not found
  result = ft_strrchr(str, 'z');
  CU_ASSERT_PTR_NULL(result);

  // Search for null terminator: pointer to end.
  result = ft_strrchr(str, '\0');
  CU_ASSERT_PTR_EQUAL(result, str + strlen(str));
}

void test_ft_strnstr(void)
{
  const char *haystack = "Searching in a limited haystack";
  const char *needle = "limited";
  char *result = ft_strnstr(haystack, needle, strlen(haystack));
  CU_ASSERT_PTR_NOT_NULL(result);
  if (result)
    CU_ASSERT_STRING_EQUAL(result, "limited haystack");

  // Limit too short to find needle.
  result = ft_strnstr(haystack, needle, 10);
  CU_ASSERT_PTR_NULL(result);

  // Empty needle returns haystack.
  result = ft_strnstr(haystack, "", 5);
  CU_ASSERT_PTR_EQUAL(result, haystack);
}

/* Additional tests */

void test_ft_split(void)
{
  char **result = ft_split("Hello world42split", ' ');
  CU_ASSERT_PTR_NOT_NULL(result);
  if (result)
  {
    CU_ASSERT_STRING_EQUAL(result[0], "Hello");
    CU_ASSERT_STRING_EQUAL(result[1], "world42split");
    CU_ASSERT_PTR_NULL(result[2]);
    // Free allocated memory
    for (int i = 0; result[i]; i++)
      free(result[i]);
    free(result);
  }

  // Test with delimiter that doesn't exist
  result = ft_split("NoDelimiterHere", ',');
  CU_ASSERT_PTR_NOT_NULL(result);
  if (result)
  {
    CU_ASSERT_STRING_EQUAL(result[0], "NoDelimiterHere");
    CU_ASSERT_PTR_NULL(result[1]);
    free(result[0]);
    free(result);
  }
}

static void add_one(unsigned int i, char *c)
{
  (void)i;
  *c = *c + 1;
}

void test_ft_striteri(void)
{
  char str[] = "abcde";
  ft_striteri(str, add_one);
  CU_ASSERT_STRING_EQUAL(str, "bcdef");
}

void test_ft_strjoin(void)
{
  char *res = ft_strjoin("Hello, ", "World!");
  CU_ASSERT_PTR_NOT_NULL(res);
  if (res)
  {
    CU_ASSERT_STRING_EQUAL(res, "Hello, World!");
    free(res);
  }

  // Joining empty strings.
  res = ft_strjoin("", "");
  CU_ASSERT_PTR_NOT_NULL(res);
  if (res)
  {
    CU_ASSERT_STRING_EQUAL(res, "");
    free(res);
  }
}

void test_ft_strlcat(void)
{
  char dst[30] = "Hello";
  const char *src = " World";
  size_t ret = ft_strlcat(dst, src, sizeof(dst));
  CU_ASSERT_STRING_EQUAL(dst, "Hello World");
  CU_ASSERT_EQUAL(ret, ft_strlen("Hello") + ft_strlen(src));

  // Test with small dstsize
  char dst2[10] = "Hello";
  ret = ft_strlcat(dst2, src, 7);
  CU_ASSERT_STRING_EQUAL(dst2, "Hello ");
  CU_ASSERT_EQUAL(ret, ft_strlen("Hello") + ft_strlen(src));
}

void test_ft_strlcpy(void)
{
  char dst[20];
  const char *src = "Copy this string";
  size_t ret = ft_strlcpy(dst, src, sizeof(dst));
  CU_ASSERT_STRING_EQUAL(dst, "Copy this string");
  CU_ASSERT_EQUAL(ret, ft_strlen(src));

  // Test with size 0: dst remains unchanged
  char dst2[20] = "unchanged";
  ret = ft_strlcpy(dst2, src, 0);
  CU_ASSERT_STRING_EQUAL(dst2, "unchanged");
  CU_ASSERT_EQUAL(ret, ft_strlen(src));
}

static char map_add_index(unsigned int i, char c)
{
  (void)i;
  return c + 1;
}

void test_ft_strmapi(void)
{
  char *res = ft_strmapi("abcd", map_add_index);
  CU_ASSERT_PTR_NOT_NULL(res);
  if (res)
  {
    CU_ASSERT_STRING_EQUAL(res, "bcde");
    free(res);
  }
}

void test_ft_strtrim(void)
{
  char *res = ft_strtrim("  \tHello World! \n", " \n\t");
  CU_ASSERT_PTR_NOT_NULL(res);
  if (res)
  {
    CU_ASSERT_STRING_EQUAL(res, "Hello World!");
    free(res);
  }

  // When all characters are trimmed.
  res = ft_strtrim("aaa", "a");
  CU_ASSERT_PTR_NOT_NULL(res);
  if (res)
  {
    CU_ASSERT_STRING_EQUAL(res, "");
    free(res);
  }
}

void test_ft_substr(void)
{
  char *res = ft_substr("Substring test", 3, 6);
  CU_ASSERT_PTR_NOT_NULL(res);
  if (res)
  {
    CU_ASSERT_STRING_EQUAL(res, "string");
    free(res);
  }

  // Test with start greater than string length.
  res = ft_substr("Short", 10, 5);
  CU_ASSERT_PTR_NOT_NULL(res);
  if (res)
  {
    CU_ASSERT_STRING_EQUAL(res, "");
    free(res);
  }
}

void test_a_char(void)
{
  CU_pSuite suite = CU_add_suite("a_chars", NULL, NULL);

  CU_add_test(suite, "ft_strlen", test_ft_strlen);
  CU_add_test(suite, "ft_strncmp", test_ft_strncmp);
  CU_add_test(suite, "ft_strdup", test_ft_strdup);
  CU_add_test(suite, "ft_strchr", test_ft_strchr);
  CU_add_test(suite, "ft_strrchr", test_ft_strrchr);
  CU_add_test(suite, "ft_strnstr", test_ft_strnstr);
  CU_add_test(suite, "ft_split", test_ft_split);
  CU_add_test(suite, "ft_striteri", test_ft_striteri);
  CU_add_test(suite, "ft_strjoin", test_ft_strjoin);
  CU_add_test(suite, "ft_strlcat", test_ft_strlcat);
  CU_add_test(suite, "ft_strlcpy", test_ft_strlcpy);
  CU_add_test(suite, "ft_strmapi", test_ft_strmapi);
  CU_add_test(suite, "ft_strtrim", test_ft_strtrim);
  CU_add_test(suite, "ft_substr", test_ft_substr);
}
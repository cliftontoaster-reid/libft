/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:32:22 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 10:41:36 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

/* Including: include/text/char.h */
/* Gitlab   : https://url.zip/6ecb187 */

/// @brief Checks if `c` is an alpha character.
/// @param c the character to check.
/// @return `1` if `c` is an alpha character and `0` if not.
int		ft_isalpha(int c);

/// @brief Checks if `c` is an digit.
/// @param c the character to check.
/// @return `1` if `c` is an digit and `0` if not.
int		ft_isdigit(int c);

/// @brief Checks if `c` is an digit or an alpha character.
/// @param c the character to check.
/// @return `1` if `c` is an digit or an alpha character and `0` if not.
int		ft_isalnum(int c);

/// @brief Checks if `c` is valid ASCII.
/// @param c the character to check.
/// @return `1` if `c` is valid ASCII and `0` if not.
int		ft_isascii(int c);

/// @brief Checks if `c` is a printable character.
/// @param c the character to check.
/// @return `1` if `c` is a printable character and `0` if not.
int		ft_isprint(int c);

/* End of   : include/text/char.h */

/* Including: include/text/str.h */
/* Gitlab   : https://url.zip/aa5fb8e */

/// @brief Returns the length of a string.
/// @param str The string to get the length of.
/// @return The length of the string.
int		ft_strlen(const char *str);

/// @brief Sets the first n bytes of a block of memory to a specified character.
/// @param s The block of memory to set.
/// @param c The character to set the memory to.
/// @param n The number of bytes to set.
/// @return A pointer to the modified block of memory.
void	*ft_memset(void *s, int c, int n);

/// @brief Sets the first n bytes of a block of memory to zero.
/// @param s The block of memory to set.
/// @param n The number of bytes to set.
void	ft_bzero(void *s, int n);

/// @brief Returns a pointer to the first occurrence of a character in a string.
/// @param s The string to search in.
/// @param c The character to search for.
/// @return A pointer to the first occurrence of the character,
///         or `NULL` if not found.
char	*ft_strchr(const char *s, int c);

/* End of   : include/text/str.h */

/* Including: include/mem/mem.h */
/* Gitlab   : https://url.zip/070d623 */

/// @brief Copies `n` bytes as if they are of type `char` from `src` to `dest`.
///
/// > This functions makes use of `malloc` the returned value must be freed
/// after use.
///
/// @param dest The destination where the bytes will be copied to.
/// @param src The source where the bytes will be copied from.
/// @param n The amount of bytes to copy.
/// @return The adress of the destination, given through `dest`.
void	*ft_memcpy(void *dest, const void *src, int n);

/// @brief Copies `n` bytes of data from `src` to `dest`.
/// @param dest the pointer to copy the data to.
/// @param src the pointer to copy the data from.
/// @param n the amount to copy in bytes.
/// @return a pointer to `dest`.
void	*ft_memmove(void *dest, const void *src, int n);

/// @brief Copies up to `size - 1` characters from the `NUL`-terminated
///        string src to dst, `NUL`-terminating the result.
/// @param dest the pointer to copy the data to.
/// @param src the pointer to copy the data from.
/// @param n the amount to copy in bytes.
/// @return the length of `src`.
int		ft_strlcpy(char *dst, const char *src, size_t size);

/// @brief appends the `NUL`-terminated string src to the end of dst. It will
///        append at most `size - strlen(dst) - 1` bytes,
///        `NUL`-terminating the result.
/// @param dest the pointer to copy the data to.
/// @param src the pointer to copy the data from.
/// @param n the amount to copy in bytes.
/// @return the initial length of dst plus the length of `src`.
int		ft_strlcat(char *dst, const char *src, size_t size);

/* End of   : include/mem/mem.h */

/* Including: include/text/char_type.h */
/* Gitlab   : https://url.zip/ffb3686 */

/// @brief Turns lowercase alpha characters into uppercase.
/// @param c the character to turn into uppercas.
/// @return if `c` is a lowercase character, it will return the character
///         as uppercase, or the original character if not one.
int		ft_toupper(int c);

/// @brief Turns uppercase alpha characters into lowercase.
/// @param c the character to turn into lowercase.
/// @return if `c` is an uppercase character, it will return the character
///         as lowercase, or the original character if not one.
int		ft_tolower(int c);

/// @brief Checks of `c` is a 'white' characters
/// @param c the character to check.
/// @return `1` if it is a white character and `0` if not.
int		ft_ciswhite(char c);

/* End of   : include/text/char_type.h */

/* Including: include/text/str_get.h */
/* Gitlab   : https://url.zip/a1e6384 */

/// @brief Finds the last occurrence of the character `c` (an unsigned char)
///        in the string pointed to by `s`.
/// @param s The string to search.
/// @param c The character to search for.
/// @return A pointer to the last occurrence of the character `c` in the
///         string `s`, or a null pointer if the character is not found.
char	*ft_strrchr(const char *s, int c);

/// @brief Compares at most the first `n` bytes of the strings `s1` and `s2`.
///
/// @param s1 The first string to compare.
/// @param s2 The second string to compare.
/// @param n The maximum number of bytes to compare.
/// @return An integer less than, equal to, or greater than zero if `s1` is
///         found, respectively, to be less than, to match, or be greater
///         than `s2`.
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/// @brief Locates the first occurrence of the character `c` (an unsigned
///        char) in the string pointed to by `s`.
/// @param s The string to search.
/// @param c The character to search for.
/// @param n The number of bytes to search.
/// @return A pointer to the located character, or a null pointer if
///         the character does not appear in the string.
void	*ft_memchr(const void *s, int c, int n);

/// @brief Locates the first occurrence of the null-terminated string
///        `little` in the string `big`, where not more than `len`
///        characters are searched.
///
/// @param big The string to search in.
/// @param little The string to search for.
/// @param len The maximum number of characters to search.
/// @return A pointer to the beginning of the substring, or a null
///         pointer if the substring is not found.
char	*ft_strnstr(const char *big, const char *little, size_t len);

/// @brief Allocates sufficient memory for a copy of the string `s`,
///        does the copy, and returns a pointer to it.
///
/// @param s The string to duplicate.
/// @return A pointer to the duplicated string. The memory for the new
///         string is obtained with `malloc(3)`,
///         and can be freed with `free(3)`.
char	*ft_strdup(const char *s);

/* End of   : include/text/str_get.h */

/* Including: include/mem/mem_get.h */
/* Gitlab   : https://url.zip/5aaa9a1 */

/// @brief Compares from the two provided pointers
///        for `n` bits as if they were a list of
///        `char`s.
/// @param s1 The first pointer.
/// @param s2 The second pointer.
/// @param n The amount of bits to check.
/// @return 0 if both are equal, otherwise it is
///         equal to the difference of the last
///         equal character.
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/// @brief Allocates memory for `size` elements of `nmemb` size.
/// @param nmemb The size of each elements.
/// @param size The amount of elements to acount for.
/// @return A pointer to the allocated memory, or `NULL` if it failed.
void	*ft_calloc(size_t nmemb, size_t size);

/* End of   : include/mem/mem_get.h */

/* Including: include/num/num_intstr.h */
/* Gitlab   : https://url.zip/5b791e7 */

/// @brief Convert a string to an integer.
///
/// The `ft_atoi()` function converts the initial portion of the string
/// pointed to by nptr to int. The behavior is the same as
///
/// ```
/// strtol(nptr, `NULL`, 10);
/// ```
///
/// except that `ft_atoi()` does not detect errors.
/// @param nptr the string to convert to a number.
/// @return The converted value or 0 on error.
int		ft_atoi(const char *nptr);

/// @brief Allocates (with malloc(3)) and returns a string representing the
///        integer received as an argument. Negative numbers must be handled
/// @param n the integer to convert.
/// @return The string representing the integer or `NULL`
///         if the allocation fails.
char	*ft_itoa(int n);

/* End of   : include/num/num_intstr.h */

/* Including: include/text/str_utils.h */
/* Gitlab   : https://url.zip/2117805 */

/// @brief Copies up to n characters from a source string to
/// a destination string.
/// @param dest The destination string to copy to.
/// @param src The source string to copy from.
/// @param n The maximum number of characters to copy.
/// @return A pointer to the destination string.
char	*ft_strncpy(char *dest, const char *src, size_t n);

/// @brief Allocates (with malloc(3)) and returns a substring from the string
/// `s`. The substring begins at index `start` and is of maximum size `len`.
///
/// > This functions makes use of `malloc` the returned
/// value must be freed after use.
///
/// @param s The string from which to create the substring.
/// @param start The start index of the substring in the string `s`.
/// @param len The maximum length of the substring.
/// @return (The substring or `NULL` if the allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len);

/// @brief Allocates (with malloc(3)) and returns a new string, which is the
/// result of the concatenation of `s1` and `s2`.
///
/// > This functions makes use of `malloc`
/// the returned value must be freed after use.
///
/// @param s1 The prefix string.
/// @param s2 The suffix string.
/// @return The new string or `NULL` if the allocation fails
char	*ft_strjoin(char const *s1, char const *s2);

/// @brief Allocates (with malloc(3)) and returns a copy of `s1` with the
/// characters specified in `set` removed from the beginning and the end of
/// the string.
/// @param s1 The string to be trimmed.
/// @param set The reference set of characters to trim.
/// @return The trimmed string or `NULL` if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set);

/* End of   : include/text/str_utils.h */

/* Including: include/text/str_split.h */
/* Gitlab   : https://url.zip/0858d93 */

/// @brief Returns the frequency of a character in a string.
/// @param str The string to search in.
/// @param c The character to count occurrences of.
/// @return The number of times the character appears in the string.
int		ft_strfreq(char *str, char c);

/// @brief Allocates (with malloc(3)) and returns an array of strings obtained
/// by splitting `s` using th character `c` as a delimiter. The array must end
/// with a `NULL` pointer.
/// @param s The string to be split.
/// @param c The delimiter character.
/// @return The array of new strings resulting from the split or `NULL` if the
/// allocation fails.
char	**ft_split(char const *s, char c);

/// @brief Duplicates at most `n` characters of the string `s`
/// @param s The string to duplicate
/// @param n The maximum number of characters to duplicate
/// @return A new string containing at most `n` characters of `s`,
/// or `NULL` if the allocation fails
char	*ft_strndup(const char *s, size_t n);

/* End of   : include/text/str_split.h */

/* Including: include/text/str_iter.h */
/* Gitlab   : https://url.zip/876af1a */

/// @brief Applies the function f to each character of the string s, passing
/// its index as the first argument and the character itself as the second.
/// A new string is created (using malloc(3)) to collect the results from
/// the successive applications of f.
/// @param s The string on which to iterate.
/// @param f The function to apply to each character.
/// @return The string created from the successive applications of `f` or `NULL`
/// if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/// @brief Applies the function `f` on each character of the string passed
/// as argument, passing its index as first argument. Each character is
/// passed by address to `f` to be modified if necessary.
/// @param s The string on which to iterate.
/// @param f The function to apply to each character.
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/* End of   : include/text/str_iter.h */

/* Including: include/mem/mem_write.h */
/* Gitlab   : https://url.zip/6199189 */

/// @brief Outputs the character `c` to the given file descriptor.
/// @param c The character to output.
/// @param fd The file descriptor on which to write.
void	ft_putchar_fd(char c, int fd);

/// @brief Outputs the string `s` to the given file descriptor.
/// @param s The string to output.
/// @param fd The file descriptor on which to write.
void	ft_putstr_fd(char *s, int fd);

/// @brief Outputs the string `s` to the given file descriptor
/// followed by a newline.
/// @param s The string to output.
/// @param fd The file descriptor on which to write.
void	ft_putendl_fd(char *s, int fd);

/// @brief Outputs the integer `n` to the given file descriptor.
/// @param n The integer to output.
/// @param fd The file descriptor on which to write.
void	ft_putnbr_fd(int n, int fd);

/* End of   : include/mem/mem_write.h */
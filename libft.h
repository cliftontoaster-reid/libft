/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:32:22 by lfiorell          #+#    #+#             */
/*   Updated: 2025/03/25 16:39:47 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

/// @brief Checks if `c` is an alpha character.
/// @param c the character to check.
/// @return `1` if `c` is an alpha character and `0` if not.
int					ft_isalpha(int c);

/// @brief Checks if `c` is an digit.
/// @param c the character to check.
/// @return `1` if `c` is an digit and `0` if not.
int					ft_isdigit(int c);

/// @brief Checks if `c` is an digit or an alpha character.
/// @param c the character to check.
/// @return `1` if `c` is an digit or an alpha character and `0` if not.
int					ft_isalnum(int c);

/// @brief Checks if `c` is valid ASCII.
/// @param c the character to check.
/// @return `1` if `c` is valid ASCII and `0` if not.
int					ft_isascii(int c);

/// @brief Checks if `c` is a printable character.
/// @param c the character to check.
/// @return `1` if `c` is a printable character and `0` if not.
int					ft_isprint(int c);

/// @brief Returns the length of a string.
/// @param str The string to get the length of.
/// @return The length of the string.
int					ft_strlen(const char *str);

/// @brief Sets the first n bytes of a block of memory to a specified character.
/// @param s The block of memory to set.
/// @param c The character to set the memory to.
/// @param n The number of bytes to set.
/// @return A pointer to the modified block of memory.
void				*ft_memset(void *s, int c, int n);

/// @brief Sets the first n bytes of a block of memory to zero.
/// @param s The block of memory to set.
/// @param n The number of bytes to set.
void				ft_bzero(void *s, int n);

/// @brief Returns a pointer to the first occurrence of a character in a string.
/// @param s The string to search in.
/// @param c The character to search for.
/// @return A pointer to the first occurrence of the character,
///         or `NULL` if not found.
char				*ft_strchr(const char *s, int c);

/// @brief Copies `n` bytes as if they are of type `char` from `src` to `dest`.
///
/// > This functions makes use of `malloc` the returned value must be freed
/// after use.
///
/// @param dest The destination where the bytes will be copied to.
/// @param src The source where the bytes will be copied from.
/// @param n The amount of bytes to copy.
/// @return The adress of the destination, given through `dest`.
void				*ft_memcpy(void *dest, const void *src, int n);

/// @brief Copies `n` bytes of data from `src` to `dest`.
/// @param dest the pointer to copy the data to.
/// @param src the pointer to copy the data from.
/// @param n the amount to copy in bytes.
/// @return a pointer to `dest`.
void				*ft_memmove(void *dest, const void *src, int n);

/// @brief Copies up to `size - 1` characters from the `NUL`-terminated
///        string src to dst, `NUL`-terminating the result.
/// @param dest the pointer to copy the data to.
/// @param src the pointer to copy the data from.
/// @param n the amount to copy in bytes.
/// @return the length of `src`.
int					ft_strlcpy(char *dst, const char *src, size_t size);

/// @brief appends the `NUL`-terminated string src to the end of dst. It will
///        append at most `size - strlen(dst) - 1` bytes,
///        `NUL`-terminating the result.
/// @param dest the pointer to copy the data to.
/// @param src the pointer to copy the data from.
/// @param n the amount to copy in bytes.
/// @return the initial length of dst plus the length of `src`.
int					ft_strlcat(char *dst, const char *src, size_t size);

/// @brief Turns lowercase alpha characters into uppercase.
/// @param c the character to turn into uppercas.
/// @return if `c` is a lowercase character, it will return the character
///         as uppercase, or the original character if not one.
int					ft_toupper(int c);

/// @brief Turns uppercase alpha characters into lowercase.
/// @param c the character to turn into lowercase.
/// @return if `c` is an uppercase character, it will return the character
///         as lowercase, or the original character if not one.
int					ft_tolower(int c);

/// @brief Checks of `c` is a 'white' characters
/// @param c the character to check.
/// @return `1` if it is a white character and `0` if not.
int					ft_ciswhite(char c);

/// @brief Finds the last occurrence of the character `c` (an unsigned char)
///        in the string pointed to by `s`.
/// @param s The string to search.
/// @param c The character to search for.
/// @return A pointer to the last occurrence of the character `c` in the
///         string `s`, or a null pointer if the character is not found.
char				*ft_strrchr(const char *s, int c);

/// @brief Compares at most the first `n` bytes of the strings `s1` and `s2`.
///
/// @param s1 The first string to compare.
/// @param s2 The second string to compare.
/// @param n The maximum number of bytes to compare.
/// @return An integer less than, equal to, or greater than zero if `s1` is
///         found, respectively, to be less than, to match, or be greater
///         than `s2`.
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/// @brief Locates the first occurrence of the character `c` (an unsigned
///        char) in the string pointed to by `s`.
/// @param s The string to search.
/// @param c The character to search for.
/// @param n The number of bytes to search.
/// @return A pointer to the located character, or a null pointer if
///         the character does not appear in the string.
void				*ft_memchr(const void *s, int c, int n);

/// @brief Locates the first occurrence of the null-terminated string
///        `little` in the string `big`, where not more than `len`
///        characters are searched.
///
/// @param big The string to search in.
/// @param little The string to search for.
/// @param len The maximum number of characters to search.
/// @return A pointer to the beginning of the substring, or a null
///         pointer if the substring is not found.
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/// @brief Allocates sufficient memory for a copy of the string `s`,
///        does the copy, and returns a pointer to it.
///
/// @param s The string to duplicate.
/// @return A pointer to the duplicated string. The memory for the new
///         string is obtained with `malloc(3)`,
///         and can be freed with `free(3)`.
char				*ft_strdup(const char *s);

/// @brief Compares from the two provided pointers
///        for `n` bits as if they were a list of
///        `char`s.
/// @param s1 The first pointer.
/// @param s2 The second pointer.
/// @param n The amount of bits to check.
/// @return 0 if both are equal, otherwise it is
///         equal to the difference of the last
///         equal character.
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/// @brief Allocates memory for `size` elements of `nmemb` size.
/// @param nmemb The size of each elements.
/// @param size The amount of elements to acount for.
/// @return A pointer to the allocated memory, or `NULL` if it failed.
void				*ft_calloc(size_t nmemb, size_t size);

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
int					ft_atoi(const char *nptr);

/// @brief Allocates (with malloc(3)) and returns a string representing the
///        integer received as an argument. Negative numbers must be handled
/// @param n the integer to convert.
/// @return The string representing the integer or `NULL`
///         if the allocation fails.
char				*ft_itoa(int n);

/// @brief Copies up to n characters from a source string to
/// a destination string.
/// @param dest The destination string to copy to.
/// @param src The source string to copy from.
/// @param n The maximum number of characters to copy.
/// @return A pointer to the destination string.
char				*ft_strncpy(char *dest, const char *src, size_t n);

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
char				*ft_substr(char const *s, unsigned int start, size_t len);

/// @brief Allocates (with malloc(3)) and returns a new string, which is the
/// result of the concatenation of `s1` and `s2`.
///
/// > This functions makes use of `malloc`
/// the returned value must be freed after use.
///
/// @param s1 The prefix string.
/// @param s2 The suffix string.
/// @return The new string or `NULL` if the allocation fails
char				*ft_strjoin(char const *s1, char const *s2);

/// @brief Allocates (with malloc(3)) and returns a copy of `s1` with the
/// characters specified in `set` removed from the beginning and the end of
/// the string.
/// @param s1 The string to be trimmed.
/// @param set The reference set of characters to trim.
/// @return The trimmed string or `NULL` if the allocation fails.
char				*ft_strtrim(char const *s1, char const *set);

/// @brief Returns the frequency of a character in a string.
/// @param str The string to search in.
/// @param c The character to count occurrences of.
/// @return The number of times the character appears in the string.
int					ft_strfreq(char *str, char c);

/// @brief Allocates (with malloc(3)) and returns an array of strings obtained
/// by splitting `s` using th character `c` as a delimiter. The array must end
/// with a `NULL` pointer.
/// @param s The string to be split.
/// @param c The delimiter character.
/// @return The array of new strings resulting from the split or `NULL` if the
/// allocation fails.
char				**ft_split(char const *s, char c);

/// @brief Duplicates at most `n` characters of the string `s`
/// @param s The string to duplicate
/// @param n The maximum number of characters to duplicate
/// @return A new string containing at most `n` characters of `s`,
/// or `NULL` if the allocation fails
char				*ft_strndup(const char *s, size_t n);

/// @brief Applies the function f to each character of the string s, passing
/// its index as the first argument and the character itself as the second.
/// A new string is created (using malloc(3)) to collect the results from
/// the successive applications of f.
/// @param s The string on which to iterate.
/// @param f The function to apply to each character.
/// @return The string created from the successive applications of `f` or `NULL`
/// if the allocation fails.
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/// @brief Applies the function `f` on each character of the string passed
/// as argument, passing its index as first argument. Each character is
/// passed by address to `f` to be modified if necessary.
/// @param s The string on which to iterate.
/// @param f The function to apply to each character.
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/// @brief Outputs the character `c` to the given file descriptor.
/// @param c The character to output.
/// @param fd The file descriptor on which to write.
void				ft_putchar_fd(char c, int fd);

/// @brief Outputs the string `s` to the given file descriptor.
/// @param s The string to output.
/// @param fd The file descriptor on which to write.
void				ft_putstr_fd(char *s, int fd);

/// @brief Outputs the string `s` to the given file descriptor
/// followed by a newline.
/// @param s The string to output.
/// @param fd The file descriptor on which to write.
void				ft_putendl_fd(char *s, int fd);

/// @brief Outputs the integer `n` to the given file descriptor.
/// @param n The integer to output.
/// @param fd The file descriptor on which to write.
void				ft_putnbr_fd(int n, int fd);

/// @brief A list of pointers to elements of any kind.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/// @brief Allocates (with `malloc(3)`) and returns a new node.
///        The member variable `content` is initialized with
///        the value of the parameter `content`. The variable
///        `next` is initialized to `NULL`.
/// @param content The content to create the node with.
/// @return The new node
t_list				*ft_lstnew(void *content);

/// @brief Adds the node `new` at the beginning of the list.
/// @param lst The address of a pointer to the first link of
///            a list.
/// @param new The address of a pointer to the node to be
///            added to the list.
void				ft_lstadd_front(t_list **lst, t_list *elem);

/// @brief Counts the number of nodes in a list.
/// @param lst The beginning of the list.
/// @return The length of the list
int					ft_lstsize(t_list *lst);

/// @brief Returns the last node of the list.
/// @param lst The beginning of the list.
/// @return Last node of the list
t_list				*ft_lstlast(t_list *lst);

/// @brief
/// @param lst The address of a pointer to the first link of
///            a list.
/// @param new The address of a pointer to the node to be
///            added to the list.
/// @return Adds the node `new` at the end of the list.
void				ft_lstadd_back(t_list **lst, t_list *elem);

/// @brief Takes as a parameter a node and frees the memory of
///        the node’s content using the function `del` given
///        as a parameter and free the node. The memory of
///        `next` must not be freed.
/// @param lst The node to free.
/// @param del The address of the function used to delete
///            the content.
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/// @brief Deletes and frees the given node and every
///        successor of that node, using the function `del`
///        and `free(3)`.
///        Finally, the pointer to the list must be set to
///        `NULL`.
/// @param lst The address of a pointer to a node.
/// @param del The address of the function used to delete
///            the content of the node.
void				ft_lstclear(t_list **lst, void (*del)(void *));

/// @brief Iterates the list `lst` and applies the function
///        `f` on the content of each node.
/// @param lst The address of a pointer to a node.
/// @param f The address of the function used to iterate on
///          the list.
void				ft_lstiter(t_list *lst, void (*f)(void *));

/// @brief
/// @param lst The address of a pointer to a node.
/// @param f The address of the function used to iterate on
///          the list.
/// @param del The address of the function used to delete
///            the content of a node if needed.
/// @return The new list or `NULL` if the allocation fails.
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/// @brief Prints formatted output to the standard output.
/// @param format The format string containing any format specifiers.
/// @return The total number of characters printed.
int					ft_printf(const char *format, ...);

/**
 * @brief Outputs formatted text to stdout using a va_list for arguments
 *
 * This function writes output to stdout,
 *  under control of the format string
 * that specifies how subsequent arguments
 * (via va_list) are converted for output.
 *
 * @param args Variable argument list containing values to be formatted
 * @param format Format string that specifies how to interpret the data
 *
 * @return The number of characters printed,
	or a negative value if an error occurs
 */
int					ft_vprintf(const char *format, va_list args);

#endif

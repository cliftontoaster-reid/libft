/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:23:11 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/11 00:50:45 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "../tests.hpp"

int main()
{
  CU_initialize_registry();
  //
  test_c_char();
  test_mem();
  test_c_int();
  test_a_char();
  test_lst();
  test_fd();
  //
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return (0);
}

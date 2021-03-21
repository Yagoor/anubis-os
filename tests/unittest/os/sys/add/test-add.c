#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "add.h"

void test_add_1(void **state)
{
  assert_true(add(5, 5) == 10);
}


void test_add_2(void **state)
{
  assert_true(add(6, 5) == 11);
}


/* These functions will be used to initialize
 *  and clean resources up after each test run */
int setup(void **state)
{
  return (0);
}


int teardown(void **state)
{
  return (0);
}


int main(void)
{
  const struct CMUnitTest tests [] =
  {
    cmocka_unit_test(test_add_1),
    cmocka_unit_test(test_add_2),
  };

  /* If setup and teardown functions are not
   *  needed, then NULL may be passed instead */
  cmocka_set_message_output(CM_OUTPUT_XML);

  int count_fail_tests =
      cmocka_run_group_tests(tests, setup, teardown);

  return (count_fail_tests);
}

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "sub.h"

void test_sub_1(void **state)
{
  assert_true(sub(5, 5) == 0);
}


void test_sub_2(void **state)
{
  assert_true(sub(6, 5) == 1);
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
    cmocka_unit_test(test_sub_1),
    cmocka_unit_test(test_sub_2),
  };

  /* If setup and teardown functions are not
   *  needed, then NULL may be passed instead */
  cmocka_set_message_output(CM_OUTPUT_XML);

  int count_fail_tests =
      cmocka_run_group_tests(tests, setup, teardown);

  return (count_fail_tests);
}

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern void test_pt_1(void **state);
extern void test_pt_2(void **state);

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
    cmocka_unit_test(test_pt_1),
    cmocka_unit_test(test_pt_2),
  };

  cmocka_set_message_output(CM_OUTPUT_XML);

  int count_fail_tests =
      cmocka_run_group_tests(tests, setup, teardown);

  return (count_fail_tests);
}

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "pt.h"

/* Two flags that the two protothread functions use. */
static int protothread1_flag, protothread2_flag;
static int protothread1_counter, protothread2_counter;
static struct pt pt1, pt2;

static int protothread1(struct pt *pt)
{
	PT_BEGIN(pt);

	while (1)
	{
		PT_WAIT_UNTIL(pt, protothread2_flag != 0);

		protothread2_flag = 0;
		protothread1_flag = 1;
		protothread1_counter++;
	}

	PT_END(pt);
}


static int protothread2(struct pt *pt)
{
	PT_BEGIN(pt);

	while (1)
	{
		protothread2_flag = 1;

		PT_WAIT_UNTIL(pt, protothread1_flag != 0);

		protothread1_flag = 0;
		protothread2_counter++;
	}
	PT_END(pt);
}


void test_pt_1(void **state)
{
	while (protothread1_counter < 10 && protothread2_counter < 10)
	{
		protothread1(&pt1);
		protothread2(&pt2);
	}
}


int setup(void **state)
{
	protothread1_counter = 0;
	protothread2_counter = 0;
	PT_INIT(&pt1);
	PT_INIT(&pt2);

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
	};

	/* If setup and teardown functions are not
	 *  needed, then NULL may be passed instead */
	cmocka_set_message_output(CM_OUTPUT_XML);

	int count_fail_tests =
	    cmocka_run_group_tests(tests, setup, teardown);

	return (count_fail_tests);
}

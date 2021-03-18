#include "os.h"

#include "add.h"

#include <stdio.h>

PT_THREAD(os_protothread(struct pt *pt))
{
	PT_BEGIN(pt);

	printf("Add %d\n", add(5, 6));

	PT_WAIT_UNTIL(pt, 1 == 1);

	printf("Add %d\n", add(5, 6));

	PT_END(pt);
}

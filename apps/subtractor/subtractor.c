#include "os.h"

#include "sub.h"

#include <stdio.h>

PT_THREAD(os_protothread(struct pt *pt))
{
	PT_BEGIN(pt);

	printf("Sub %d\n", sub(6, 5));

	PT_WAIT_UNTIL(pt, 1 == 1);

	printf("Sub %d\n", sub(6, 5));

	PT_END(pt);
}

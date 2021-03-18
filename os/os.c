#include "pt.h"

extern struct pt os_pt;
extern int os_protothread(struct pt *pt);

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	PT_INIT(&os_pt);

	os_protothread(&os_pt);

	return (0);
}

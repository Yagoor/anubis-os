#include "os.h"

static struct pt os_pt;

int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  PT_INIT(&os_pt);

  do
  {
  } while (PT_SCHEDULE(os_protothread(&os_pt)));

  return (0);
}

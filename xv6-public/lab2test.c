#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
    printf(1, "Inital priority of pid 2: %d\n", get_priority(2));

    printf(1, "setting PID 2 to priority 3\n");
    set_priority(2, 3);
    printf(1, "Priority of pid 2: %d\n", get_priority(2));

    printf(1, "Attempting to set PID 2 priority to 55\n");
    set_priority(2, 55);
    printf(1, "Priority of pid 2: %d\n", get_priority(2));

    exit();
}
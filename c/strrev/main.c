#include <unistd.h>
#include "strrev.h"

int main ()
{
    char arr[7] = "ABCDEF\0";

    write(0, arr, getsize(arr));
    write(0, "\n", 1);
    write(0, strreev(arr), getsize(arr));
    write(0, "\n", 1);
	return 0;
}

#include <unistd.h>
#include "strrev.h"

int	getsize(char *array)
{
	int	size;

	size = 0;
	while (array[size] != 0)
	{
		size++;
	}
	return (size);
}

char	*strreev(char *array)
{
	int	end;
	int	start;
	int	temp;

	start = 0;
	end = getsize(array) - 1;
	while (start < end)
	{
		temp = array[end];
		array[end] = array[start];
		array[start] = temp;
		end--;
		start++;
	}
	return (array);
}

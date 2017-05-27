#include "../include/checker.h"
#include "../include/structure.h"

int		ps_is_sort(int *arr, int n)
{
	int		i;

	i = 0;
	while ((n - 1) > i)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

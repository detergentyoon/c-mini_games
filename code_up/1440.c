#include <stdio.h>

int main()
{
	int arr[100];
	int n;

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);

	for (int i = 0; i < n; i++)
	{
		printf("%d:", i + 1);
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (arr[i] > arr[j])
					printf(" >");
				else if (arr[i] < arr[j])
					printf(" <");
				else if (arr[i] == arr[j])
					printf(" =");
			}
		}
		printf("\n");
	}

	return 0;
}
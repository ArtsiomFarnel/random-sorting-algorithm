#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void main (void) {

	int exit = 1;
	while (exit) {
		exit = 0;
		srand(time(NULL));

		int array_length;
		printf("Input array length (less than 100000): ");
		while (1) {
			fflush(stdin);
			if (scanf("%d", &array_length) == 1) {
				if (array_length > 100000 || array_length <= 0) {
					array_length = 100000;
					printf("Array length is %d", array_length);
				}
				break;
			}
			else printf("Input an integer value: ");
		}

		clock_t tic = clock();

		int arr[array_length];
		for (int i = 0; i < array_length; i++)
			arr[i] = rand() % array_length;

		printf("Generated array:\n");
		for (int i = 0; i < array_length; i++)
			printf("%d ", arr[i]);

		int left, right, tmp, counter = 0, flag = 1;
		printf("\nSorting...");
		while (flag) {
			flag = 0;
			left = rand() % array_length;
			right = rand() % array_length;

			if ((left < right && arr[left] > arr[right]) || (left > right && arr[left] < arr[right])) {
				tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
			}

			for (int j = 0; j < array_length-1; j++)
				if (arr[j] > arr[j+1]) {
					flag = 1;
					break;
				}

			counter++;
		}
		printf("\nIterations: %d", counter);

		printf("\nSorted array:\n");
		for (int i = 0; i < array_length; i++)
			printf("%d ", arr[i]);

		clock_t toc = clock();
		printf("\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

		fflush(stdin);
		char choice;
		printf("Do you want to continue? [Y/N]: ");
		scanf("%c", &choice);
		if (choice == 'y' || choice == 'Y') exit = 1;
	}

	printf("Press any key...");
	getch();
}

// .exe = https://drive.google.com/file/d/1wkoVQLiaDilv0SuahEp-GMpNxBgtgTte/view?usp=sharing
// use numbers less than 1000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int main () {
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	printf("Input array length:\n");
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		//scanf("%d", &arr[i]);
		arr[i] = rand() % 10000;
	}
	int x, y;
	int tmp = 0;
	int bad = 1;
	int k = 0;
	while (bad) {
		bad = 0;
		x = rand() % (n);
		//printf("x=%d\n", x);
		y = rand() % (n);
		//printf("y=%d\n", y);
		if ((x < y && arr[x] > arr[y]) || (x > y && arr[x] < arr[y])) {
			tmp = arr[x];
			arr[x] = arr[y];
			arr[y] = tmp;
		}
		for (int j = 0; j < n-1; j++) {
			if (arr[j] > arr[j+1]) {
				bad = 1;
			}
		}
		/*if (k == 1000000) {
			printf("1M\n");
			//printf("%d", arr[n-1]);
			//printf("\n");
			k = 0;
		}*/
		k++;
	}
	printf("Iterations: ");
	printf("%d", k);
	printf("\n");
	printf("Result: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	getch();
	return 0;
}

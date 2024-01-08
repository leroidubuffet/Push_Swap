#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_ordered(int n) {
	for (int i = -n/2; i < n/2; i++) {
		printf("%d ", i);
	}
	printf("\n");
}

void print_reversed(int n) {
	for (int i = n/2 - 1; i >= -n/2; i--) {
		printf("%d ", i);
	}
	printf("\n");
}

void print_random(int n) {
	int *arr = malloc(n * sizeof(int));
	if (arr == NULL) {
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++) {
		arr[i] = i - n/2;  // Filling array with numbers from -n/2 to n/2-1
	}

	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <number> <ordered|reversed|random>\n", argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);
	if (n <= 0) {
		fprintf(stderr, "Please provide a positive number.\n");
		return 1;
	}

	srand(time(NULL));  // Seed for the random number generator

	if (strcmp(argv[2], "ordered") == 0) {
		print_ordered(n);
	} else if (strcmp(argv[2], "reversed") == 0) {
		print_reversed(n);
	} else if (strcmp(argv[2], "random") == 0) {
		print_random(n);
	} else {
		fprintf(stderr, "Invalid option. Choose from ordered, reversed, or random.\n");
		return 1;
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELVES 1000

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int arr[], int low, int high) {
  int pivot = arr[high];

  int i = low;

  for (int j = low; j <= high; j++) {
    if (arr[j] > pivot) {
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[i], &arr[high]);
  return i;
}
void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}
int readFromFile(char *fileName) {
  FILE *file = fopen("elflist", "r");
  if (!file) {
    perror("Error opening the file");
    return 1;
  }
  char line[100];
  int elfCalories[MAX_ELVES] = {0};
  int currentSumBuffer = 0;
  int elfCount = 0;

  while (fgets(line, sizeof(line), file)) {
    char *newline = strchr(line, '\n');
    if (newline)
      *newline = '\0';

    if (strlen(line) == 0) {
      elfCalories[elfCount++] = currentSumBuffer;
      currentSumBuffer = 0;
      continue;
    }

    currentSumBuffer += atoi(line);
  }
  if (currentSumBuffer != 0) {
    elfCalories[elfCount++] = currentSumBuffer;
  }
  fclose(file);

  int highestCalorieIndex = 0;
  for (int i = 0; i < elfCount; i++) {

    if (elfCalories[i] > elfCalories[highestCalorieIndex]) {
      highestCalorieIndex = i;
    }
  }
  printf("Elf with the most calories: Elf %d\n", highestCalorieIndex + 1);
  printf("He carries %d calories\n", elfCalories[highestCalorieIndex]);

  // Part 2. Find the sum of the three highest calorie holders
  quicksort(elfCalories, 0, elfCount - 1);

  // Get the sum of the 3 largest:
  int sumOfThreeLargest = elfCalories[0] + elfCalories[1] + elfCalories[2];
  printf("The sum of the 3 Largest: %d\n", sumOfThreeLargest);
  printf("Sorted in Descending order: \n");
  for (int i = 0; i < elfCount; i++) {
    printf("Elf %d: %d\n", i, elfCalories[i]);
  }

  return 0;
}
int main() { readFromFile("elflist"); }

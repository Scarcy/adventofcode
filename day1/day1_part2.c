#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char *name;
  int value;
} word_digit;
word_digit digits[10] = {
    {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
    {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
};
char *words[10] = {"",     "one", "two",   "three", "four",
                   "five", "six", "seven", "eight", "nine"};
int findDigitFromString(char *str) {

  printf("String to Check: %s\n", str);
  for (int i = 1; i < 10; ++i) {
    if (strstr(str, words[i]) != NULL) {
      printf("Found: %s\n", words[i]);
      return i;
    }
  }

  return -1;
}
// int findDigitFromString(char *str) {
//
//   printf("String to Check: %s\n", str);
//   if (strcmp(str, "one") == 0)
//     return 1;
//   if (strcmp(str, "two") == 0)
//     return 2;
//   if (strcmp(str, "three") == 0)
//     return 3;
//   if (strcmp(str, "four") == 0)
//     return 4;
//   if (strcmp(str, "five") == 0)
//     return 5;
//   if (strcmp(str, "six") == 0)
//     return 6;
//   if (strcmp(str, "seven") == 0)
//     return 7;
//   if (strcmp(str, "eight") == 0)
//     return 8;
//   if (strcmp(str, "nine") == 0)
//     return 9;
//
//   return -1;
// }
int main() {
  FILE *fp = fopen("input", "r");
  char line[1024];
  unsigned int sum = 0;

  while (fgets(line, 1024, fp)) {
    int firstDigit = -1, lastDigit = -1;

    char tempWord[20] = {0};
    int wordIndex = 0;

    for (int i = 0; line[i] != '\0' && line[i] != '\n'; ++i) {
      if (line[i] >= '0' && line[i] <= '9') {
        int digit = line[i] - '0';
        if (firstDigit == -1) {
          firstDigit = digit;
        }
        lastDigit = digit;
        wordIndex = 0;
      } else {
        tempWord[wordIndex++] = line[i];
        tempWord[wordIndex] = '\0';

        int digit = findDigitFromString(tempWord);
        if (digit != -1) {
          printf("Digit found: %d\n", digit);
          i--;
          if (firstDigit == -1)
            firstDigit = digit;

          lastDigit = digit;
          wordIndex = 0;
        }
      }
    }
    printf("First: %d\t Last: %d\n", firstDigit, lastDigit);
    sum += (firstDigit * 10) + lastDigit;
  }
  printf("Sum: %d\n", sum);
}

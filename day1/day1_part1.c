#include <ctype.h>
#include <stdio.h>
int main() {
  FILE *fp = fopen("input", "r");
  int ch;
  unsigned int sum = 0;
  int first = -1;
  int last = -1;
  while ((ch = fgetc(fp)) != EOF) {
    if (isdigit(ch)) {
      if (first == -1) {
        first = ch - '0';
      }

      last = ch - '0';
    }

    if (ch == '\n') {
      sum += (first * 10) + last;
      printf("first: %d, last: %d\n", first, last);

      first = -1;
      last = -1;
    }
  }
  printf("sum: %d\n", sum);
}

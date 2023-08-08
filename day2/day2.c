#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("guide.txt", "r");
  if (!file) {
    perror("Error opening the file");
    return EXIT_FAILURE;
  }
  char opponentsChoices[2600];
  char yourChoices[2600];
  int score = 0;
  int score2 = 0;
  char line[10];
  int index = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    char *newline = strchr(line, '\n');
    if (newline) {
      *newline = '\0';
    }
    opponentsChoices[index] = line[0];
    yourChoices[index] = line[2];
    index++;
  }
  fclose(file);
  // Debug print statements
  // for (int i = 0; i < index; i++) {
  //   printf("Opponent: %c -- You: %c\n", opponentsChoices[i], yourChoices[i]);
  // }

  for (int i = 0; i < index; i++) {
    char oc = opponentsChoices[i];
    char yc = yourChoices[i];
    switch (yc) {
    case 'X':
      score += 1;
      break;
    case 'Y':
      score += 2;
      break;
    case 'Z':
      score += 3;
      break;
    default:
      break;
    }
    // Opponent chooses Rock
    if (oc == 'A') {
      if (yc == 'X')
        score += 3;
      else if (yc == 'Y')
        score += 6;
      else if (yc == 'Z')
        score += 0;
    }
    // Opponent chooses Paper
    if (oc == 'B') {

      if (yc == 'X')
        score += 0;
      else if (yc == 'Y')
        score += 3;
      else if (yc == 'Z')
        score += 6;
    }
    // Opponent chooses Scissors
    if (oc == 'C') {
      if (yc == 'X')
        score += 6;
      else if (yc == 'Y')
        score += 0;
      else if (yc == 'Z')
        score += 3;
    }

    // Part 2
    // X = Lose, Y = Draw, Z = Win
    switch (oc) {
    case 'A':
      switch (yc) {
      case 'X':
        score2 += 3;
        break;
      case 'Y':
        score2 += 4;
        break;
      case 'Z':
        score2 += 8;
        break;
      default:
        break;
      }
      break; // Add this
    case 'B':
      switch (yc) {
      case 'X':
        score2 += 1;
        break;
      case 'Y':
        score2 += 5;
        break;
      case 'Z':
        score2 += 9;
        break;
      default:
        break;
      }
      break; // Add this
    case 'C':
      switch (yc) {
      case 'X':
        score2 += 2;
        break;
      case 'Y':
        score2 += 6;
        break;
      case 'Z':
        score2 += 7;
        break;
      default:
        break;
      }
      break; // This is correct
    }
  }
  printf("Your score is: %d\n", score);
  printf("Your score following the guide is: %d\n", score2);
  return 0;
}

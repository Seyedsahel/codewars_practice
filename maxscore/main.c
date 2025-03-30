#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *highestScoringWord(const char *str) {
  int max_score = 0, temp_score = 0;

  char *temp_index = str;
  char *max_index;
  while (*str != '\0') {

    if (*str != ' ') {
      temp_score += *str - 96;
    } else {
      if (temp_score > max_score) {
        max_index = temp_index;
        max_score = temp_score;
      }
      temp_score = 0;
      temp_index = str + 1;
    }
    str++;
  }
  char *result = malloc(strlen(max_index) * sizeof(char));
  memccpy(result, max_index, ' ', strlen(max_index));
  return result;
}
int main() {

  const char *str = "this is";
  char *res = highestScoringWord(str);
  printf("%s", res);
  return 0;
}

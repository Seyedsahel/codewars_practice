#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


char *alphabet_position(const char *text) {
  char *index;

  char *result = malloc(strlen(text) * 4);
  char *temp_res = result;
  index = text;
  int num;
  while (*index != '\0') {
    if (isalpha(*index)) {
      num = tolower(*index) - 96;
      result+=sprintf(result, "%d ", num);
    }
    index++;
  }
  *result = '\0';
  return temp_res;
}

int main() {
  const char *str = "The sunset";
  char *res = alphabet_position(str);
  printf("%s", res);
  return 0;
}

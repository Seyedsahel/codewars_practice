#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *DuplicateEncoder(const char *string) {
  // return a nul-terminated, heap-allocated string
  int records[128] = {0};
  char *index = string;
  while (*index != '\0') {
    records[tolower(*index)]++;
    index++;
  }
  char *result = malloc(strlen(string) + 1);
  index = string;
  while (*index != '\0') {
    if (records[tolower(*index)] == 1) {
      *result = '(';
    } else {
      *result = ')';
    }
    result++;
    index++;
  }
  *result = '\0'; 
  return result - strlen(string);
}

int main() {

  const char *str = "babaie";
  char *res = DuplicateEncoder(str);
  printf("%s", res);
  return 0;
}

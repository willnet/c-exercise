#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage %s str1 str2", argv[0]);
    return 0;
  }
  char *str1 = argv[1];
  char *str2 = argv[2];

  int length_str1 = strlen(str1);
  int length_str2 = strlen(str2);
  printf("str1 is %s\n", str1);
  printf("str2 is %s\n", str2);
  int d[length_str1][length_str2];
  int cost, del, ins, rep;
  for (int i = 0; i < length_str1; i++) {
    printf("hi");
    d[i][0] = 0;
  }
  for (int i = 0; i < length_str2; i++) {
    d[0][i] = 0;
  }

  for (int i = 1; i < length_str1; i++) {
    for (int j = 1; j < length_str2; j++) {
      if (str1[i-1] == str2[j-1]) {
        cost = 0;
      } else {
        cost = 1;
      }
      del = d[i-1][j] + 1;
      ins = d[i][j-1] + 1;
      rep = d[i-1][j-1] + cost;
      if (del <= ins && del <= rep) {
        d[i][j] = del;
      } else if ( ins <= del && ins <= rep) {
        d[i][j] = ins;
      } else {
        d[i][j] = rep;
      }
    }
  }
  printf("levenshtein is %d\n", d[length_str1-1][length_str2-1]);
}
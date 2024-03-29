#include<stdio.h>

// 主にビューティフルコードより引用

int match(char *regexp, char *text);
int matchhere(char *regexp, char *text);
int matchstar(int c, char *regexp, char *text);

int main(int argc, char *argv[])
{
  if(match(argv[1], argv[2]) == 1) {
    printf("match!!!\n");
    return 0;
  } else {
    printf("unmatch!!!\n");
    return 1;
  }
}

int match(char *regexp, char *text)
{
  if(regexp[0] == '^')
    return matchhere(regexp+1, text);
  do {
      if(matchhere(regexp, text))
        return 1;
  } while (*text++ != '\0');
  return 0;
}

int matchhere(char *regexp, char *text)
{
  if(regexp[0] == '\0')
    return 1;
  if(regexp[1] == '*')
    return matchstar(regexp[0], regexp+2, text);
  if(regexp[0] == '$' && regexp[1] == '\0')
    return *text == '\0';
  if(*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
    return matchhere(regexp+1, text+1);
  return 0;
}

int matchstar(int c, char *regexp, char *text)
{
  do {
    if(matchhere(regexp, text))
      return 1;
  } while(*text != '\0' && (*text++ == c || c == '.'));
  return 0;
}


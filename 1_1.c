#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
  if (argc == 1) {
    printf("No arguments\n");
    return 0;
  }
  if (argc > 3) {
    printf("Too many arguments\n");
    return 0;
  }
  int num = 0;
  int i=0;
  if (argv[2][0] == '-') {
    printf("Second argument must be a positive number\n");
    return 0;
  }
  while(argv[2][i]){
    num = num * 10 + (argv[2][i] - '0');
    i+=1;}
  if (!strcmp(argv[1], "-h")) {
    if (num > 100) {
      printf("No multiples\n");
      return 0;
    }
    for (int i = num; i <= 100; i += num) {
      printf("%d ", i);
      printf("\n");
    }
  } 
  else if (!strcmp(argv[1], "-p")) {
    if (num <= 1)
      printf("Number is neither simple nor composite\n");
    else {
      for (unsigned int i = 2; i < num; i++)
        if (num % i == 0) {
          printf("Number is composite\n");
          return 0;
        }
      printf("Number is simple\n");
    }
  }
  else if (!strcmp(argv[1], "-s")) {
    for (int i = 0; i <= strlen(argv[2]); i++) {
      printf("%c ", argv[2][i]);
      printf(" ");
    }
    printf("\n");
  }
  else if (!strcmp(argv[1], "-e")) {
    if (num > 10)
      printf("Incorrect number for this argument\n");
    else {
      for (int i = 1; i <= 10; i++) {
        int p = i;
        for (int j = 1; j <= num; j++) {
          printf("%d ", p);
          p *= i;
        }
        printf("\n");
      }
    }
  } 
  else if (!strcmp(argv[1], "-a")) {
    printf("%d\n", (num * (num + 1)) / 2);
  } 
  else if (!strcmp(argv[1], "-f")) {
    unsigned int res = 1;
    for (int i = 2; i <= num; i++) {
      res *= i;
    }
    printf("%d\n", res);
  } 
  else {
    printf("Wrong argument(s)\n");
    return 0;
  }
  return 0;
}

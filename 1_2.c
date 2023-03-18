#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int Change(char* numc){
int num=0;
  int i=0;
   while(numc[i]){
      num = num * 10 + (numc[i] - '0');
    i+=1;
}
  return num;
  }
void QuadEquat(int a,int b,int c){
  printf("x1=%f\n",-b+sqrt(b*b-4*a*c));
  printf("x2=%f\n",-b-sqrt(b*b-4*a*c));
}
void Multiplicity(int x, int y){
  if (x%y==0){
    printf("кратно\n");
    return;
  }
   printf("не кратно\n");
}
void Triangle(int a,int b,int c){
  if (a+b>c && a+c>b && b+c>a ){
   printf("может быть сторонами треугольника\n");
    return;
  }
   printf("не может быть сторонами треугольника\n");
}

int main(int argc, char** argv){
  int i=0;
  int num=0;
  if (!(argv[1][2]==0 &&(argv[1][0]=='-' || argv[1][0]=='/'))){
    printf("не правильно набранный флаг\n");
    return 0;
  }
  switch (argv[1][1]){
    case 'q': if (argc!=5){
      printf("не соответсвует колличество параметров");
      break;
      }
      QuadEquat(Change(argv[2]),Change(argv[3]),Change(argv[4]));;
    case 'm': if (argc!=4){
      printf("не соответсвует колличество параметров");
      break;
      }
      Multiplicity(Change(argv[2]),Change(argv[3]));;
    case 't': if (argc!=5){
      printf("не соответсвует колличество параметров");
      break;
      }
      Triangle(Change(argv[2]),Change(argv[3]),Change(argv[4]));
    }
  return 0;
}

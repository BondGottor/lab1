#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Multiplicity(int numm){
  if (numm>100){
    printf("нет кратных чисел в пределе до 100\n");
    return;
  }
  for (int i=numm;i<=100;i+=numm){
    printf("%d \n", i);
    }
  }
int Sqrt(int num){
  int right=num;
  int left=0;
  int mid=0;
  for (int i=num/2;i!=0;i/=2){
    mid=right-i;
    if (mid*mid>num){
      right=mid;
    }
    else if (mid*mid<num){
      left=mid;
    }
    else{
      return mid;
    }
  }
}
void Prime(int nump){
  if (nump==0 || nump==1){
    printf("не простое не сложное");
    return;
  }
  int max=Sqrt(nump)+1;
  for(int i=2;i<=max;i+=1){
   if(nump%i==0){
     printf("составное\n");
     return;
   }
    }
    printf("простое\n");
}
void ChByCh(int numc){
  int ten=10;
    while(numc/ten){
    ten*=10;
  }
  while(numc){
    ten/=10;
    printf("%d ",numc/ten);
    numc%=ten;
  }
  printf("\n");
}
void Exponentiation(int nume){
  if (nume>10){
    printf("должно быть не больше 10\n");
    return;
  }
  int prnt=1;
  for (int i=1;i<=10;i++){
    prnt=i;
    for (int j=1;j<=nume;j++){
      printf("%d ",prnt);
      prnt*=i;
    }
    printf("\n");
    }
  }
void Summa(int nums){
  long unsigned int prnt=(nums * (nums + 1)) / 2;
  printf("%lu\n", prnt);
  }
void Factorial(int numf){
  long long unsigned int fact=1;
  for (int i=2;i<=numf;i++){
    fact*=i;
    }
  printf("%llu \n",fact);
}
int main(int argc, char** argv){
  int i=0;
  int num=0;
  while(argv[2][i]){
    num = num * 10 + (argv[2][i] - '0');
    i+=1;}
  printf("%d \n", argv[1][1]);
  switch (argv[1][1]){
    case 'h': Multiplicity(num);
    case 'p': Prime(num);
    case 's': ChByCh(num);
    case 'e': Exponentiation(num);
    case 'a': Summa(num);
    case 'f': Factorial(num);
    }
}

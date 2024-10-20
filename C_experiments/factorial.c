#include <stdio.h>

int factorial(int n){
  if(n == 0){
    return 1;      
  } else{
    return n*factorial(n-1);      
  }
}

int main()
{
    printf("Hello World\n");
    
    int fact = factorial(3);
    printf("factorial = %d\n", fact);

    return 0;
}

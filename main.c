#include<stdio.h>
#include<stdlib.h>
int main()
    {
  int a=5;
  change(&a);
  printf("%d",a);
    }
    int change(int *a)
    {
        *a=*a+5;
    }

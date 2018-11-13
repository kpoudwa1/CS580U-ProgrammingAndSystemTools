#include <stdlib.h>
#include <stdio.h>
#pragma GCC diagnostic ignored "-Wreturn-local-addr"
#pragma GCC diagnostic ignored "-Wfree-nonheap-object"

void f1(){
  int *a = malloc(sizeof(int) * 3);
  for (int i = 0; i < 3; i++){
    a[i] = i;
  }
  free(a);
}

int * f2(){
  int a[10];
  for (int i = 0; i < 9; i++){
    a[i] = i;
  }
  for (int i = 0; i < 9; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  return a;
}

int f3(){
  char * cptr = malloc(sizeof(char)*10);
  cptr[9] = 'a';
  char junk = 'a';
  if(junk == 0){
      printf("Junk is zero.");
  }
  //free(&junk);
  free(cptr);
}

/** DO NOT ALTER THE MAIN FUNCTION **/

int main(){
  f1();
  f2();
  f3();
}

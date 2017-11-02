#include "utils.h"


int main(int argc, char *argv[]){
  FILE *src;
  float *teste;
  int size;
  
  src=fopen("matriz.txt","r");
  teste=readVector(src, &size);
  printVector(teste,size);
  fclose(src);
  free(teste);
  return 0;
}

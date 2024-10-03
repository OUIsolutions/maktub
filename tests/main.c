
#include "MakTub.h"

MakTubNameskace mak;

int main(){

  mak = newMakTubNameskace();

  MakTub *self = mak.newMakTub("samuel");

  printf("\n\tseed: %d\n", self->started);

  return EXIT_SUCCESS;
}





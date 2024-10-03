
/*
self->seed is used to know which seed it is.
*/

#include "../../../MakTub.h"

MakTubNameskace mak;

int main(){

  mak = newMakTubNameskace();

  MakTub *self = mak.newMakTub("Anything");

  printf("\n\tself seed: %s\n", self->seed);

  return 0;
}





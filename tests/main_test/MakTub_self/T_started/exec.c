/*
self->started serves to know if the MakTub structure was used or if you prefer to start it.
*/

#include "../../../MakTub.h"

MakTubNameskace mak;

int main(){

  mak = newMakTubNameskace();

  MakTub *it_was_started = mak.newMakTub("Anything");
  MakTub *has_not_been_started = mak.newMakTub("Anything");

  mak.generate_num(it_was_started, 1, 10);

  printf("\n\tit_was_started: %d\n\thas_not_been_started: %d\n", it_was_started->started, has_not_been_started->started);

  return 0;
}







/*
It also defines the probability percentage of executing something with: "subscribe_function"
*/

#include "MakTub.h"
MakTubNamespace mak;

void print_nil(MakTub *self){
  printf("\tNILL\n");
}

void print_hello(MakTub *self){
  printf("\tHello Word\n");
}


int main(){

  mak = newMakTubNameskace();

  MakTub *self = mak.newMakTub("your seed here");

  MakTubeGenerationAction * nome = mak.newGenerationAction(self);
  mak.actions.subscribe_function(nome, 0.25, print_nil);
  mak.actions.subscribe_function(nome, 0.75, print_hello);
  mak.actions.perform(nome);

  mak.free(self);

  return 0;
}

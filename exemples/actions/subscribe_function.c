

/*
It also defines the probability percentage of executing something with: "subscribe_function"
*/

#include "MakTub.h"

#define FIRST_PROBABILITY 0.2
#define SECOND_PROBABILITY 0.4

void print_nil(MakTub *self){
  printf("\tNILL\n");
}

void print_hello(MakTub *self){
  printf("\tHello Word\n");
}

MakTubNameskace mak;

int main(){

  mak = newMakTubNameskace();

  MakTub *self = mak.newMakTub("Anythingasdfgh");

  

  printf("\n");
  for(int index = 0; index < 12; index++){
    printf("%d", index);
    MakTubeGenerationAction * nome = mak.newGenerationAction(self);
    mak.actions.subscribe_function(nome, FIRST_PROBABILITY, print_nil);
    mak.actions.subscribe_function(nome, SECOND_PROBABILITY, print_hello);
    mak.actions.perform(nome);
  }

  printf("\n\tend\n");

  mak.free(self);

  return 0;
}





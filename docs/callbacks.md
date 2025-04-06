

## Callbacks
you can determine a callback to be executed on each probability


~~~c


#include "MakTub.h"
MakTubNamespace mak;


void print_in_portuguese(MakTub *self){

  printf("Bem Vindo %s\n", (char*)self->current_args);
}

void print_in_spanish(MakTub *self){
    printf("Bienvenido %s\n", (char*)self->current_args);
}

void print_in_english(MakTub *self){
  printf("Welcome %s\n",(char*)self->current_args);
}


int main(){

  mak = newMakTubNameskace();

  MakTub *self = mak.newMakTub("your seed here");
  self->current_args = "Mateus";
  MakTubeGenerationAction * nome = mak.newGenerationAction(self);
  mak.actions.subscribe_function(nome, 0.33, print_in_portuguese);
  mak.actions.subscribe_function(nome, 0.33, print_in_spanish);
  mak.actions.subscribe_function(nome, 0.33, print_in_english);

  mak.actions.perform(nome);

  mak.free(self);

  return 0;
}

~~~

## Passing Args to callback

~~~c


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

~~~


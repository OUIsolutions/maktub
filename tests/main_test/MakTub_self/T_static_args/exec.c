
/*
self->static_args It serves to put arguments in itself.
*/

#include "../../../MakTub.h"

typedef struct props{
  int age;
  char *name;
  bool win;
}props;

MakTubNameskace mak;

void persons_luck(MakTub *self){

  props *person = (props *)self->static_args;

  person->win = mak.generate_num(self, 0, 1);
}

int main(){

  mak = newMakTubNameskace();

  MakTub *self = mak.newMakTub("Anything");

  props person = {0};
  person.age = 18;
  person.name = "chaves";

  self->static_args = (void *)&person;

  persons_luck(self);

  printf("\n\t%s win: %s\n", person.name, person.win?"true":"false");

  return 0;
}





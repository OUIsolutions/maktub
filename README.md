

Examples using the above library


~~~c


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





~~~

~~~c



/*
It is also possible to generate pseudo randomness in lists.
*/

#include "MakTub.h"

MakTubNameskace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  const char *list[] = {"chaves", "Dona Florinda", "Shr. Girafales", "Nhonho"};

  const char *chosen_person = mak.generate_choice(obj, (void **)list, sizeof(list) / sizeof(char *));

  printf("\n\tchose person: %s\n", chosen_person);
  
  mak.free(obj);
  
  return 0;
}





~~~

~~~c


/*
With MakTup you can generate tokens through seeds, choosing the number of characters and which characters are accepted.
*/

#include "MakTub.h"

#define ACCEPTED_CARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz !@#$%*()"
#define NUMBER_OF_CARACTERS 12

MakTubNameskace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  const char *token_generated = ACCEPTED_CARACTERS; //mak.generate_token(obj, NUMBER_OF_CARACTERS, ACCEPTED_CARACTERS);
  
  printf("%s\n",token_generated);
  
  mak.free(obj);
  
  return 0;
}





~~~

~~~c
#include "MakTub.h"
MakTubNameskace mak;

int main(){
    mak = newMakTubNameskace();
    MakTub * obj = mak.newMakTub("your seed here");
    int num = mak.generate_num(obj,0,100);
    printf("%d\n",num);
    mak.free(obj);
    return 0;
}

~~~

~~~c

/*
self->seed is used to know which seed it is.
*/

#include "MakTub.h"

MakTubNameskace mak;

int main(){

  mak = newMakTubNameskace();

  MakTub *self = mak.newMakTub("Anything");

  printf("\n\tself seed: %s\n", self->seed);

  mak.free(self);

  return 0;
}





~~~

~~~c
/*
self->started serves to know if the MakTub structure was used or if you prefer to start it.
*/

#include "MakTub.h"

MakTubNameskace mak;

int main(){

  mak = newMakTubNameskace();

  MakTub *it_was_started = mak.newMakTub("Anything");
  MakTub *has_not_been_started = mak.newMakTub("Anything");

  mak.generate_num(it_was_started, 1, 10);

  printf("\n\tit_was_started: %d\n\thas_not_been_started: %d\n", it_was_started->started, has_not_been_started->started);

  mak.free(it_was_started);
  mak.free(has_not_been_started);

  return 0;
}





~~~

~~~c

/*
self->static_args It serves to put arguments in itself.
*/

#include "MakTub.h"

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

  mak.free(self);

  return 0;
}





~~~



.
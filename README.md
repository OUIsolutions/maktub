
## Maktub
Maktube its a pseudo randon generative library designed to generate
theorem tests, procedural objects constructions and anything that you need
pseudo random usage

## Install
These lib its designed to be as dumb as possible


## Quick Usage
these above example generates a simple rand number betwen  0 and 100


~~~c
#include "MakTub.h"
MakTubNamespace mak;

int main(){
    mak = newMakTubNameskace();
    MakTub * obj = mak.newMakTub("your seed here");
    int num = mak.generate_num(obj,0,100);
    printf("%d\n",num);
    mak.free(obj);
    return 0;
}

~~~

## Generating Tokens
you also can generate tokens of diferent sizes of diferent chars


~~~c


/*
With MakTup you can generate tokens through seeds, choosing the number of characters and which characters are accepted.
*/

#include "MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  char *token = mak.generate_token(obj,10,mak.seqs.allpha_nuns);
  printf("%s\n",token);
  mak.free(obj);

  return 0;
}

~~~

## Choice
you can choice betwen lists with generate choice functionality


~~~c



/*
It is also possible to generate pseudo randomness in lists.
*/

#include "MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  const char *list[] = {"chaves", "Dona Florinda", "Shr. Girafales", "Nhonho"};

  const char *chosen_person = (char*)mak.generate_choice(obj, (void **)list, sizeof(list) / sizeof(char *));

  printf("\n\tchose person: %s\n", chosen_person);

  mak.free(obj);

  return 0;
}

~~~


## Probabilities
you can set probabilities for for switching elements

~~~c



/*
It is also possible to generate pseudo randomness in lists.
*/

#include "MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  MaktubGenerationNum *nuns = mak.newGenerationNum(obj);
  mak.num.add_probability(nuns,0.33);
  mak.num.add_probability(nuns,0.33);
  mak.num.add_probability(nuns,0.33);

  printf("chosed alternative %d",mak.num.perform(nuns));
  mak.free(obj);
  return 0;
}

~~~

its also possible to use it at a boolean strategy

~~~c



/*
It is also possible to generate pseudo randomness in lists.
*/

#include "MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  MaktubGenerationNum *nuns = mak.newGenerationNum(obj);
  mak.num.add_probability(nuns,0.25);
  mak.num.add_probability(nuns,0.75);

  bool you_play_minecraft = mak.num.perform(nuns);
  if(you_play_minecraft){
      printf("you play minecraft\n");
  }
  if(!you_play_minecraft){
      printf("you dont play minecraft\n");
  }
  mak.free(obj);
  return 0;
}

~~~

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


## Seed Control
all pseudo random numbers are generated based on the seed and on the
generation ,where you can modify and controll it


~~~c
#include "MakTub.h"
MakTubNamespace mak;

int main(){
    mak = newMakTubNameskace();
    MakTub * obj = mak.newMakTub("your seed here");
    int num = mak.generate_num(obj,0,100);
    printf("first =%d\n",num);
    mak.set_generation(obj,0);
    int num2 = mak.generate_num(obj,0,100);
    printf("second = %d\n",num2); //it will be equal to first
    mak.free(obj);
    return 0;
}

~~~

## Making Seed random modifications
you can make small seed modifications to test varios hipoteses


~~~c
#include "MakTub.h"
MakTubNamespace mak;

int main(){
    mak = newMakTubNameskace();
    MakTub * obj = mak.newMakTub("your seed here");
    int num = mak.generate_num(obj,0,100);
    printf("seed = %s\n",obj->seed);
    printf("first =%d\n",num);
    mak.aply_seed_modification(obj,(int[]){0,1,2},3,mak.seqs.allpha_nuns);
    int num2 = mak.generate_num(obj,0,100);
    printf("seed = %s\n",obj->seed);
    printf("second = %d\n",num2); //it will be equal to first
    mak.free(obj);
    return 0;
}

~~~


d
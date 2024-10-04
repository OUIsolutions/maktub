
## Maktub
Maktub its a pseudo randon generative library designed to generate
theorem tests, procedural objects constructions and anything that you need
pseudo random usage

## Install
These lib its designed to be as dumb as possible,for usage just download the
[Amalgamation File](https://github.com/OUIsolutions/maktub/releases/download/v0.001/MakTub.h) int your project and include it directly into your main

```c
#include "MakTub.h"
int main(){
}
```


## Full Folder
you also can run the project directy from folder, just copy the **src** folder into
your project and include the **src/one.c** file into yout main
```c
#include "src/one.c"
int main(){

}

```
## Building From Scracth
if you want you can build from scracth the almagamation ,or work into the project
for builiding just run:
```sh
sh pre_build.sh && ./build.out
```
it will generate the amalgamation in **release** , and execute all the unit tests

#### SilverChain Path
these project uses [Silverchain](https://github.com/OUIsolutions/SilverChain) as
the default includer, and we recomen you to use, to a better development on files modification
for usage in these project, download silverchain and put the **silverchain binary**
into the main root dir, and run the sh **watch.sh** file


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
    printf("seed = %s\n",mak.get_seed(obj));
    printf("first =%d\n",num);
    mak.aply_seed_modification(obj,(int[]){0,1,2},3,mak.seqs.allpha_nuns);
    int num2 = mak.generate_num(obj,0,100);
    printf("seed = %s\n",mak.get_seed(obj));
    printf("second = %d\n",num2); //it will be equal to first
    mak.free(obj);
    return 0;
}

~~~

### Finding Seed
you can find seed based on lambda blueprints and verifiers

~~~c
#include "MakTub.h"

MakTubNamespace mak;


void *blue_print_generator(MakTub *self){
    char *nation[] = {"Brazilian","American","Portuguese"};
    char *chosen_nation = Maktub_generate_choice(self,(void**)nation,sizeof(nation)/sizeof(char*));
    short chose_age = Maktub_generate_num(self,1, 120);
    char *sentence = (char*)calloc(1000, sizeof(char));
    sprintf(sentence,"I am %s and i am %d years old",chosen_nation,chose_age);
    return sentence;
}

bool sentence_validator(MakTub *self,void *result){
    char *formatted = (char*)result;
    const char *TARGET = "I am Brazilian and i am 27 years old";
    return strcmp(formatted, TARGET) == 0;
}

char * find_seed(){
    MakTub *maktube_obj = mak.newMakTub("eai parsa suave ");

       int POSITION_TO_MODIFY[] = {0,1,2,3};
       int POSITION_SIZE = sizeof(POSITION_TO_MODIFY)/sizeof(int);
       int MAX_TRY = 1000;
       bool found = mak.aply_seed_modification_til_find(
           maktube_obj,
           POSITION_TO_MODIFY,
           POSITION_SIZE,
           mak.seqs.allpha_nuns,
           blue_print_generator,
           sentence_validator,
           free,
           MAX_TRY
       );

       if(found){
           char *copy = strdup(maktube_obj->seed);
           mak.free(maktube_obj);
           return copy;
       }
       mak.free(maktube_obj);
       return NULL;
}

int main(){

    // 8
   mak =newMakTubNameskace();

   mak = newMakTubNameskace();

   char *found_seed = find_seed();
   if(found_seed){
       printf("found seed '%s'\n",found_seed);
       MakTub *test_obj = mak.newMakTub(found_seed);
       char *generation = (char*)blue_print_generator(test_obj);
       printf("generation:'%s'\n",generation);
       mak.free(test_obj);
       free(found_seed);
       free(generation);
   }
   if(!found_seed){
       printf("seed not found \n");
   }

    return 0;

}

~~~

### Finding many seeds
if you need you can find many seeds at once with string arrays



~~~c
#include "MakTub.h"

MakTubNamespace mak;


void *blue_print_generator(MakTub *self){
    char *nation[] = {"Brazilian","American","Portuguese"};
    char *chosen_nation = Maktub_generate_choice(self,(void**)nation,sizeof(nation)/sizeof(char*));
    short chose_age = Maktub_generate_num(self,1, 120);
    char *sentence = (char*)calloc(1000, sizeof(char));
    sprintf(sentence,"I am %s and i am %d years old",chosen_nation,chose_age);
    return sentence;
}

bool sentence_validator(MakTub *self,void *result){
    char *formatted = (char*)result;
    const char *TARGET = "I am Brazilian and i am 27 years old";
    return strcmp(formatted, TARGET) == 0;
}

int main(){

    // 8
   mak =newMakTubNameskace();

   mak = newMakTubNameskace();

   MakTub *maktube_obj = mak.newMakTub("eai parsa suave ");

   int POSITION_TO_MODIFY[] = {0,1,2,3};
   int POSITION_SIZE = sizeof(POSITION_TO_MODIFY)/sizeof(int);
   int MAX_TRY = 10000;
   int MAX_ITENS = 10;

   MakTubeStringArray *itens = mak.aply_seed_modification_returning_string_array(
          maktube_obj,
          POSITION_TO_MODIFY,
          POSITION_SIZE,
          mak.seqs.allpha_nuns,
          blue_print_generator,
          sentence_validator,
          free,
          MAX_TRY,
          MAX_ITENS
    );
    for(int i =0; i < itens->size;i++){
        printf("seed: '%s'\n",mak.string_array.get_str(itens,i));
    }

    mak.free(maktube_obj);

    return 0;

}

~~~



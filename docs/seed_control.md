
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



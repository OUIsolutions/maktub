#include "../../MakTub.h"

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

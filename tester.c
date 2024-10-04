#include "src/one.c"
#include "extra/doTheWorld.h"
#include "extra/CHashManipulator.h"
#include "tests/MakTub.h"
#include <string.h>


MakTubNamespace mak;
CHashNamespace chash;
DtwNamespace dtw;

void *blue_print_generator(MakTub *self){
    char *nation[] = {"Brazilian","American","Portuguese"};
    char *chosen_nation = Maktub_generate_choice(self,(void**)nation,sizeof(nation)/sizeof(char*));
    short chose_age = Maktub_generate_num(self,1, 120);
    char *sentence = (char*)calloc(1000, sizeof(char));
    sprintf(sentence,"I am %s and i am %d years old",chosen_nation,chose_age);
    return sentence;
}

int main(){

    // 8
   mak =newMakTubNameskace();
   chash = newCHashNamespace();
   dtw = newDtwNamespace();
   mak = newMakTubNameskace();
   MakTub *test_obj = mak.newMakTub("64W1parsa suave ");
   char *generation = (char*)blue_print_generator(test_obj);
   printf("resultado: %s\n",generation);
   mak.free(test_obj);


    return 0;

}

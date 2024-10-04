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

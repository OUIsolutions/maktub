
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end



MakTub * newMakTub(const char *seed){
    MakTub * self = (MakTub*)malloc(sizeof(MakTub));
    *self = (MakTub){0};
    self->seed = seed;
    self->garbage =newUniversalGarbage();

    self->seed_factor = MAKTUB_DEFAULT_SEED_FACTOR;
    self->num_factor = MAKTUB_DEFAULT_NUM_FACTOR;
    self->num_multiplier = MAKTUB_DEFAULT_NUM_MULTIPLYER;
    self->start_multiplier =MAKTUB_DEFAULT_START_MULTIPLYER;
    return self;
}
MaktubGenerationNum * MakTub_newGenerationNum(MakTub *self){
    return private_new_MaktubGenerationNum(self);
}

void private_MakTub_start(MakTub *self){
    if(self->started){
        return;
    }
    self->started = true;
    unsigned long str_size  = strlen(self->seed);
    for(unsigned long i = 0; i < str_size;i++ ){
        self->num_seed += self->seed[i] << (self->seed_factor-1);
    }
    self->num_seed *= self->start_multiplier;
}

int  Maktub_generate_num(MakTub *self,  int min,  int  max){


    self->generation+=1;
    private_MakTub_start(self);

    self->num_seed += (self->generation >> (self->num_factor-1)) * self->num_multiplier;
    srand((unsigned int)self->num_seed);

    if(min>=0){
        max -=min;
    }
    if(min <0){
        max+=(min *-1);
    }

    int result = rand();
    result = result % max;
    result+=min;



    return result;
}


void * Maktub_generate_choice(MakTub *self,void **elements,int elements_size){
    int chose = Maktub_generate_num(self, 0,elements_size);
    return elements[chose];
}


char * MakTub_generate_token(MakTub *self ,int token_size,const char *valid_chars){

    unsigned long total_chars = strlen(valid_chars);
    char *target_token = malloc(token_size * sizeof(char));
    UniversalGarbage_add_simple(self->garbage, target_token);

    target_token[token_size]  ='\0';
    for(int i =0; i <token_size; i++){
        char chosen_index = Maktub_generate_num(self,0,total_chars-1);
        target_token[i]  = valid_chars[chosen_index];
    }
    return target_token;
}

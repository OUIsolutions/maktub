
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end



MakTub * newMakTub(const char *seed){
    MakTub * self = (MakTub*)malloc(sizeof(MakTub));
    *self = (MakTub){0};
    self->seed = seed;
    self->seed_factor = MAKTUB_DEFAULT_SEED_FACTOR;
    self->num_factor = MAKTUB_DEFAULT_NUM_FACTOR;
    self->num_multiplier = MAKTUB_DEFAULT_NUM_MULTIPLYER;
    self->start_multiplier =MAKTUB_DEFAULT_START_MULTIPLYER;
    return self;
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

int  Maktub_generate_num(MakTub *self,  int min, unsigned int  max){
    self->generation+=1;
    self->num_seed += (self->generation >> (self->num_factor-1)) * self->num_multiplier;
    srand((unsigned int)self->num_seed);
    if(min < 0){
        max += (min *-1);
    }
    int result = rand();
    result = result % max;
    if(min < 0){
        result-=min;
    }
    return result;
}


void * Maktub_choice(MakTub *self,void **elements,int elements_size){
    int chose = Maktub_generate_num(self, 0,elements_size-1);
    return elements[chose];
}


char * MakTub_token(MakTub *self ,int token_size,const char *valid_chars){

}


//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end



MakTub * newMakTub(const char *seed,...){
     MakTub * self = (MakTub*)malloc(sizeof(MakTub));
    *self = (MakTub){0};

    va_list args;
    va_start(args, seed);
    private_Maktube_set_seed_by_vaarg(self,seed,args);
    va_end(args);


    self->garbage =newUniversalGarbage();
    self->seed_factor = MAKTUB_DEFAULT_SEED_FACTOR;
    self->start_multiplier =MAKTUB_DEFAULT_START_MULTIPLYER;
    return self;
}

void private_Maktube_set_seed_by_vaarg(MakTub *self,const char *seed_fmt,va_list args){
    self->started = false;
    va_list args_copy;
    va_copy(args_copy, args);
    int required_size = vsnprintf(NULL,0, seed_fmt, args_copy);
    self->seed = (char*)malloc((required_size+1)* sizeof(char));
    vsnprintf(self->seed, sizeof(char) * (required_size+1),seed_fmt, args);
    self->seed[required_size] = '\0';
    va_end(args_copy);
}

void MakTub_set_seed(MakTub *self,const char *seed,...){
    va_list args;
    va_start(args, seed);
    private_Maktube_set_seed_by_vaarg(self,seed,args);
    va_end(args);
}

void private_MakTub_generate_num_seed(MakTub *self){
    if(self->started){
        return;
    }
    self->started = true;
    self->num_seed = 0;
    unsigned long str_size  = strlen(self->seed);

    for(unsigned long i = 0; i < str_size;i++ ){
        self->num_seed += self->seed[i] << (self->seed_factor-1);
    }

    self->num_seed *= self->start_multiplier;
}


MaktubGenerationNum * MakTub_newGenerationNum(MakTub *self){
    MaktubGenerationNum *obj= private_new_MaktubGenerationNum(self);
    UniversalGarbage_add(self->garbage,private_MaktubGenerationNum_free,obj);
    return obj;
}

MakTubeGenerationAction * MakTub_newGenerationAction(MakTub *self){
    MakTubeGenerationAction *obj = private_newMakTubeGenerationAction(self);
    UniversalGarbage_add(self->garbage,private_free_MakTubeGenerationAction,obj);
    return obj;
}



int  Maktub_generate_num(MakTub *self,  int min,  int  max){

    min-=1;
    self->generation+=1;
    private_MakTub_generate_num_seed(self);
    srand(self->num_seed * self->generation);


    if(min>=0){
        max -=min;
    }
    if(min <0){
        max+=(min *-1);
    }

    int result = rand();
    result = result % max+1;
    result+=min;



    return result;
}


void * Maktub_generate_choice(MakTub *self,void **elements,int elements_size){
    int chose = Maktub_generate_num(self, 0,elements_size-1);
   return elements[chose];
}


char * MakTub_generate_token(MakTub *self ,int token_size,const char *valid_chars){

    unsigned long total_chars = strlen(valid_chars);
    char *target_token = (char*)malloc(token_size * sizeof(char));
    UniversalGarbage_add_simple(self->garbage, target_token);

    target_token[token_size]  ='\0';
    for(int i =0; i <token_size; i++){
        char chosen_index = Maktub_generate_num(self,0,total_chars-1);
        target_token[i]  = valid_chars[chosen_index];
    }
    return target_token;
}
void MakTub_free(MakTub *self){
    UniversalGarbage_free(self->garbage);
    free(self->seed);
   free(self);
}

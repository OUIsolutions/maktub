
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
void  MakTub_set_generation(MakTub *self,int generation){
    self->generation =generation;
}

void MakTub_set_seed(MakTub *self,const char *seed,...){
    self->started = false;
    va_list args;
    va_start(args, seed);
    private_Maktube_set_seed_by_vaarg(self,seed,args);
    va_end(args);
}

void MakTub_aply_seed_modification(MakTub *self,int points[], int point_sizes,const char *valid_chars){
    if(self->meta_object == NULL){
        self->meta_object = newMakTub("%s",self->seed);
    }
    int seed_size = strlen(self->seed);
    int valid_chars_size  = strlen(valid_chars);
    for(int i =0; i < point_sizes; i++){
        int chose_index = points[i];
        if(chose_index >=seed_size){
            continue;;
        }
        int chose_index_to_replace = Maktub_generate_num(self->meta_object,0,valid_chars_size-1);
        char char_to_replace = valid_chars[chose_index_to_replace];
        self->seed[chose_index] = char_to_replace;
    }
    self->started = false;
}


void private_MakTub_generate_num_seed(MakTub *self){
    if(self->started){
        return;
    }
    self->started = true;
    self->num_seed = 1;
    self->generation = 0;

    unsigned long str_size  = strlen(self->seed);

    for(unsigned long i = 0; i < str_size;i++ ){
        self->num_seed = MakTube_generate_random_num_based_on_seed(
            (self->num_seed + (unsigned int)self->seed[i]+i),
            MAKTUBE_MIN_SEED,
            MAKTUB_MAX_SEED
        );
    }




   // printf("%lld\n",self->num_seed);
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



long long   Maktub_generate_num(MakTub *self,  long long  min, long long   max){
    self->generation+=1;
    private_MakTub_generate_num_seed(self);
    unsigned long long  current_seed = self->num_seed + self->generation;
    return MakTube_generate_random_num_based_on_seed(
         current_seed,
         min,
         max
    );
}


void * Maktub_generate_choice(MakTub *self,void **elements,int elements_size){
    int chose = Maktub_generate_num(self, 0,elements_size-1);
   return elements[chose];
}


char * MakTub_generate_token(MakTub *self ,int token_size,const char *valid_chars){

    unsigned long total_chars = strlen(valid_chars);
    char *target_token = (char*)malloc((token_size+2) * sizeof(char));
    UniversalGarbage_add_simple(self->garbage, target_token);

    target_token[token_size]  ='\0';
    for(int i =0; i <token_size; i++){
        char chosen_index = Maktub_generate_num(self,0,total_chars-1);
        target_token[i]  = valid_chars[chosen_index];
    }
    return target_token;
}
bool Maktube_aply_seed_modification_til_find(
    MakTub *self,
    int *points,
    int points_size,
    const char *valid_chars,
    void *(*blueprint_callback)(MakTub *self),
    bool (*validator_callback)(MakTub *self,void *obj),
    void (*releaser)(void *obj),
    long max_try
){
    for(int k = 0; k < max_try; k++){
        void *test_case = blueprint_callback(self);
        bool result = validator_callback(self,test_case);

        if(releaser){
            releaser(test_case);
        }
        if(result){
            return true ;
        }
        MakTub_aply_seed_modification(self,points,points_size,valid_chars);
    }
    return false;
}
MakTubeStringArray * Maktube_aply_seed_modification_returning_string_array(
    MakTub *self,
    int *points,
    int points_size,
    const char *valid_chars,
    void *(*blueprint_callback)(MakTub *self),
    bool (*validator_callback)(MakTub *self,void *obj),
    void (*releaser)(void *obj),
    long max_try,
    int max_itens
){
    MakTubeStringArray * itens =newMakTubeStringArray();
    UniversalGarbage_add(self->garbage,MakTubeStringArray_free, itens);

    for(int k = 0; k < max_try; k++){

        if(itens->size > max_itens){
            return itens;
        }
        void *test_case = blueprint_callback(self);
        bool result = validator_callback(self,test_case);

        if(releaser){
            releaser(test_case);
        }
        if(result){
            MakTubeStringArray_append(itens, self->seed);
        }
        MakTub_aply_seed_modification(self,points,points_size,valid_chars);
    }

    return itens;
}

void MakTub_free(MakTub *self){
    UniversalGarbage_free(self->garbage);
    if(self->meta_object){
        MakTub_free(self->meta_object);
    }
    free(self->seed);
   free(self);
}

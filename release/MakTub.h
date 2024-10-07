
#ifndef MAKTUB_H
#define MAKTUB_H
#ifndef maktub_native
#define maktub_native
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#endif


#ifndef maktub_dependency
#define maktub_dependency

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


#ifndef UNIVERSAL_GARBAGE_H
#ifndef UNIVERSAL_GARBAGE_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define UniversalGarbage_create_empty_struct(name,element_type) \
(element_type*)malloc(sizeof(element_type));    \
*name = (element_type){0};


#define UniversalGarbage_cast(value) ((void**)&value)


#define UniversalGarbage_add(garbage,deallocator_callback,value) \
    rawUniversalGarbage_add(garbage,(void(*)(void*))deallocator_callback,UniversalGarbage_cast(value))

#define UniversalGarbage_add_simple(garbage,value) \
     UniversalGarbage_add(garbage,free,value)


#define UniversalGarbage_add_return(garbage,deallocator_callback,value) \
        UniversalGarbage_add(garbage->return_values,deallocator_callback,value)


#define UniversalGarbage_add_simple_return(garbage,value) \
    UniversalGarbage_add_simple(garbage->return_values,value)



#define  UniversalGarbage_remove(garbage,value) \
    rawUniversalGarbage_remove(garbage,UniversalGarbage_cast(value));


#define  UniversalGarbage_disconnect(garbage,value) \
    rawUniversalGarbage_disconnect(garbage,UniversalGarbage_cast(value));




#define UniversalGarbage_reallocate(garbage,value) \
    rawUniversalGarbage_reallocate(garbage,UniversalGarbage_cast(value))


#define UniversalGarbage_resset(garbage,value) \
    rawUniversalGarbage_resset(garbage,UniversalGarbage_cast(value))



#ifndef PRIVATE_UNIVERSGAL_GARBAGE_ELEMENT_TYPE
#define PRIVATE_UNIVERSGAL_GARBAGE_ELEMENT_TYPE
typedef struct privateUniversalGarbageElement{
    void **pointer;
    void (*deallocator_callback)(void *element);
    void *pointed_value;
}privateUniversalGarbageElement;
#endif



#ifndef  PRIVATE_UNIVERSAL_GARBAGE_TYPE
#define PRIVATE_UNIVERSAL_GARBAGE_TYPE


typedef  struct UniversalGarbage{

    struct UniversalGarbage *return_values;
    privateUniversalGarbageElement **elements;
    int  elements_size;
    bool is_the_root;

}UniversalGarbage;
#endif














void private_UniversalGarbageSimpleElement_free_pointed_value(privateUniversalGarbageElement *self);


void private_UniversalGarbageSimpleElement_free(privateUniversalGarbageElement *self);

privateUniversalGarbageElement * private_newUniversalGarbageSimpleElement(void (*dealocator_callback)(void *element), void **pointer);







UniversalGarbage * newUniversalGarbage();

UniversalGarbage * private_new_MainUniversalGarbage();



bool  rawUniversalGarbage_resset(UniversalGarbage *self, void **pointer);

bool  rawUniversalGarbage_remove(UniversalGarbage *self, void **pointer);

bool  rawUniversalGarbage_disconnect(UniversalGarbage *self, void **pointer);

bool rawUniversalGarbage_reallocate(UniversalGarbage *self, void **pointer);

bool  rawUniversalGarbage_add(UniversalGarbage *self,  void (*dealocator_callback)(void *element), void **pointer);

void private_UniversalGarbage_free_all_sub_elements(UniversalGarbage *self);

void UniversalGarbage_free_including_return(UniversalGarbage *self);

void UniversalGarbage_free(UniversalGarbage *self);





#ifdef __cplusplus
}
#endif

#define UNIVERSAL_GARBAGE_H
#endif










privateUniversalGarbageElement * private_newUniversalGarbageSimpleElement(void (*dealocator_callback)(void *element), void **pointer){

    privateUniversalGarbageElement * self = UniversalGarbage_create_empty_struct(
        self,
        privateUniversalGarbageElement
    );
    self->pointer = pointer;
    self->deallocator_callback = dealocator_callback;
    self->pointed_value = *pointer;
    return  self;
}
void private_UniversalGarbageSimpleElement_free_pointed_value(privateUniversalGarbageElement *self){
    if(self->pointed_value){
        self->deallocator_callback(self->pointed_value);
        self->pointed_value = NULL;
    }
}

void private_UniversalGarbageSimpleElement_free(privateUniversalGarbageElement *self){
    private_UniversalGarbageSimpleElement_free_pointed_value(self);
    free(self);
}






UniversalGarbage * private_new_MainUniversalGarbage(){
    UniversalGarbage *self = UniversalGarbage_create_empty_struct(self,UniversalGarbage)
    self->elements = (privateUniversalGarbageElement**)malloc(0);
    self->is_the_root = false;
    return self;
}

UniversalGarbage * newUniversalGarbage(){
    UniversalGarbage *self = UniversalGarbage_create_empty_struct(self,UniversalGarbage)
    self->is_the_root = true;
    self->elements = (privateUniversalGarbageElement**)malloc(0);
    self->return_values =private_new_MainUniversalGarbage();

    return self;
}




bool  rawUniversalGarbage_reallocate(UniversalGarbage *self, void **pointer){

    if(self->is_the_root){

        if(rawUniversalGarbage_reallocate(self->return_values,pointer)){
            return true;
        }
    }


    for(int i = 0; i < self->elements_size; i++){

        privateUniversalGarbageElement *current = self->elements[i];
        bool reallocate = current->pointer == pointer;

        if(reallocate){
            current->pointed_value = *pointer;
            return true;
        }
    }
    return false;
}

bool rawUniversalGarbage_resset(UniversalGarbage *self, void **pointer){

    if(self->is_the_root){
        if(rawUniversalGarbage_resset(self->return_values,pointer)){
            return true;
        }
    }


    for(int i = 0; i < self->elements_size; i++){
        privateUniversalGarbageElement *current = self->elements[i];
        bool resset = current->pointer == pointer;
        if(resset){
            private_UniversalGarbageSimpleElement_free_pointed_value(current);
            current->pointed_value = *pointer;
            return true;
        }
    }
    return  false;

}
bool  rawUniversalGarbage_remove(UniversalGarbage *self, void **pointer){
    if(self->is_the_root){
        if(rawUniversalGarbage_remove(self->return_values,pointer)){
            *pointer = NULL;
            return true;
        }
    }

    for(int i = 0; i < self->elements_size; i++){
        privateUniversalGarbageElement *current = self->elements[i];
        if(current->pointer == pointer){
            private_UniversalGarbageSimpleElement_free(current);
            self->elements_size-=1;
            bool its_not_the_last = i < self->elements_size;
            if(its_not_the_last){
                self->elements[i] = self->elements[self->elements_size];

            }
            *pointer = NULL;
            return  true;
        }
    }
    return  false;
}
bool  rawUniversalGarbage_disconnect(UniversalGarbage *self, void **pointer){
    if(self->is_the_root){
        if(rawUniversalGarbage_disconnect(self->return_values,pointer)){
            return true;
        }
    }

    for(int i = 0; i < self->elements_size; i++){
        privateUniversalGarbageElement *current = self->elements[i];
        if(current->pointer == pointer){
            free(current);
            self->elements_size-=1;
            bool its_not_the_last = i < self->elements_size;
            if(its_not_the_last){
                privateUniversalGarbageElement *last_element =  self->elements[self->elements_size];
                self->elements[i] = last_element;
            }
            return true;
        }
    }
    return  false;



}
bool  rawUniversalGarbage_add(UniversalGarbage *self,  void (*dealocator_callback)(void *element), void **pointer){

    if(!pointer){
        return false;
    }

    if(*pointer){
        for(int i = 0; i < self->elements_size; i++){
            privateUniversalGarbageElement *current = self->elements[i];
            if(current->pointed_value == *pointer){
                return false;
            }
        }
    }




    self->elements = (privateUniversalGarbageElement**)realloc(
            self->elements,
            (self->elements_size + 1) * sizeof(privateUniversalGarbageElement*)
    );



    self->elements[self->elements_size] = private_newUniversalGarbageSimpleElement(dealocator_callback, pointer);
    self->elements_size+=1;

    return  true;

}



void  private_UniversalGarbage_free_all_sub_elements(UniversalGarbage *self){
    for(int i = 0; i < self->elements_size; i++){
        private_UniversalGarbageSimpleElement_free(self->elements[i]);
    }
    free(self->elements);
}

void UniversalGarbage_free_including_return(UniversalGarbage *self){
    private_UniversalGarbage_free_all_sub_elements(self);
    if(self->is_the_root){
        UniversalGarbage_free(self->return_values);
    }
    free(self);
}

void UniversalGarbage_free(UniversalGarbage *self){
    private_UniversalGarbage_free_all_sub_elements(self);

    if(self->is_the_root){

        UniversalGarbage *return_garbage = self->return_values;
        for(int i = 0; i < return_garbage->elements_size; i++){
            free(return_garbage->elements[i]);
        }

        free(return_garbage->elements);
        free(return_garbage);
    }


    free(self);
}






#define UNIVERSAL_GARBAGE_H
#endif


#endif


#ifndef maktub_consts
#define maktub_consts

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end
#define MAKTUBE_SUFFLE 7
#define MAKTUBE_FACTOR 1.55
#define MAKTUBE_ONE_MILLION 1000000
#define MAKTUBE_ONE_BILION 1000000000
#define MAKTUBE_MIN_SEED MAKTUBE_ONE_MILLION
#define MAKTUB_MAX_SEED MAKTUBE_ONE_BILION

#define MAKTUB_PI 3141592



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end



#ifndef MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA
#define MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA 10000
#endif



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


#define MAKTUB_MAX_CHANCES -2



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


#ifndef MAKTUB_GENERATION_PLOTAGE_AREA
#define MAKTUB_GENERATION_PLOTAGE_AREA 10000
#endif



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end
#define MAKTUBE_NUMBERS  "0123456789"

#define MAKTUBE_NUMBERS        "0123456789"
#define MAKTUBE_UPPERCASE      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define MAKTUBE_LOWERCASE      "abcdefghijklmnopqrstuvwxyz"
#define MAKTUBE_LOWERCASE_NUM  "abcdefghijklmnopqrstuvwxyz0123456789"
#define MAKTUBE_UPPERCASE_NUM  "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define MAKTUBE_ALFHA_NUNS            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"


#endif


#ifndef maktub_struct
#define maktub_struct

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


typedef struct MakTub
{

   struct MakTub *meta_object;
   char *seed;
   unsigned long long    num_seed;
   UniversalGarbage *garbage;
   bool started;

   int generation;

   void *static_args;
   void *current_args;
   int index;
   double probability;

}MakTub;



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

typedef  struct MakTubeStringArray{

    char **itens;
    int allocated_size;
    int size;

}MakTubeStringArray;


#endif


#ifndef maktub_structB
#define maktub_structB

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end



typedef struct MaktubGenerationNum{
    MakTub *root_obj;
    double chances[MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA];
    int size_chanches;

}MaktubGenerationNum;


#endif


#ifndef maktub_structC
#define maktub_structC

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

typedef struct privateMakTubeAction{
    void (*generation_callback)(void *MakTubeGeneration);
}privateMakTubeAction;




typedef struct MakTubeGenerationAction{
    MakTub *root_obj;
    MaktubGenerationNum *nums;
    privateMakTubeAction actions[MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA];



    int size_actions;

}MakTubeGenerationAction;


#endif


#ifndef maktub_structD
#define maktub_structD

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end
typedef struct MakTubeStringArrayNamespace{

    MakTubeStringArray * (*newStringArray)();
    void (*append)(MakTubeStringArray *self,const char *item);
    int  (*get_size)(MakTubeStringArray *self);
    const char * (*get_str)(MakTubeStringArray *self,int index);

    void (*free)(MakTubeStringArray *self);

} MakTubeStringArrayNamespace;



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end




typedef struct GenerationActionNamespace{


    void (*subscribe_function)(
        MakTubeGenerationAction *self,
        double chance,
        void (*generation_callback)(MakTub *item)
    );

    void (*perform)(MakTubeGenerationAction *self);

}GenerationActionNamespace;


//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


typedef struct  GenerationNumNamespace{
   

int (*add_probability)(MaktubGenerationNum *self,double chance);
int  (*perform)(MaktubGenerationNum *self);
double  (*get_probability_num)(MaktubGenerationNum *self,int index);


}GenerationNumNamespace;



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

typedef struct MakTubSequencialsNamespace {
    const char *numbers;           // Números
    const char *uppercase;         // Letras maiúsculas
    const char *lowercase;         // Letras minúsculas
    const char *lowercase_num;     // Minúsculas + Números
    const char *uppercase_num;     // Maiúsculas + Números
    const char *allpha_nuns;               // Todas as letras + Números
} MakTubSequencialsNamespace;


#endif


#ifndef maktub_structE
#define maktub_structE

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

typedef struct MakTubNamespace{

     char *(*get_seed)(MakTub *self);
    int (*get_generation)(MakTub *self);
    void(*set_generation)(MakTub *self,int generation);
    void (*set_seed)(MakTub *self,const char *seed,...);
    void (*aply_seed_modification)(MakTub *self,int points[], int point_sizes,const char *valid_chars);
    MakTub * (*newMakTub)(const char *seed,...);
    long long   (*generate_num)(MakTub *self,  long long  min,  long long   max);
    MaktubGenerationNum * (*newGenerationNum)(MakTub *self);
    MakTubeGenerationAction * (*newGenerationAction)(MakTub *self);
    void * (*generate_choice)(MakTub *self,void **elements,int elements_size);
    char * (*generate_token)(MakTub *self ,int token_size,const char *valid_chars);
    MakTubeStringArray * (*aply_seed_modification_returning_string_array)(
        MakTub *self,
        int *points,
        int points_size,
        const char *valid_chars,
        void *(*blueprint_callback)(MakTub *self),
        bool (*validator_callback)(MakTub *self,void *obj),
        void (*releaser)(void *obj),
        long max_try,
        int max_itens
    );

    bool (*aply_seed_modification_til_find)(
        MakTub *self,
        int *points,
        int points_size,
        const char *valid_chars,
        void *(*blueprint_callback)(MakTub *self),
        bool (*validator_callback)(MakTub *self,void *obj),
        void (*releaser)(void *obj),
        long max_try
    );
    GenerationNumNamespace num;
    GenerationActionNamespace actions;
    MakTubSequencialsNamespace  seqs;
    MakTubeStringArrayNamespace string_array;

void (*free)(MakTub *self);

}MakTubNamespace;


#endif


#ifndef maktub_fdeclare
#define maktub_fdeclare

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


MakTubeGenerationAction * private_newMakTubeGenerationAction(MakTub *Maktube_obj);


void MakTubeGenerationAction_subscribe_function(
    MakTubeGenerationAction *self,
    double chance,
    void (*generation_callback)(MakTub *item)
);


void MakTubeGenerationAction_perform(MakTubeGenerationAction *self);




void private_free_MakTubeGenerationAction(MakTubeGenerationAction *self);



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end



MakTub * newMakTub(const char *seed,...);

void MakTub_set_generation(MakTub *self,int generation);

int MakTub_get_generation(MakTub *self);

void MakTub_aply_seed_modification(MakTub *self,int points[], int point_sizes,const char *valid_chars);


void private_MakTub_generate_num_seed(MakTub *self);

void private_Maktube_set_seed_by_vaarg(MakTub *self,const char *seed_fmt,va_list args);

void MakTub_set_seed(MakTub *self,const char *seed,...);

char * MakTub_get_seed(MakTub *self);

long long   Maktub_generate_num(MakTub *self,  long long  min, long long   max);

MaktubGenerationNum * MakTub_newGenerationNum(MakTub *self);

MakTubeGenerationAction * MakTub_newGenerationAction(MakTub *self);

void * Maktub_generate_choice(MakTub *self,void **elements,int elements_size);

bool Maktube_aply_seed_modification_til_find(
    MakTub *self,
    int *points,
    int points_size,
    const char *valid_chars,
    void *(*blueprint_callback)(MakTub *self),
    bool (*validator_callback)(MakTub *self,void *obj),
    void (*releaser)(void *obj),
    long max_try
);

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
);


char * MakTub_generate_token(MakTub *self ,int token_size,const char *valid_chars);

void MakTub_free(MakTub *self);



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end



MaktubGenerationNum * private_new_MaktubGenerationNum(MakTub *Maktub_obj);


int MaktubGenerationNum_add_probability(MaktubGenerationNum *self,double chance);

int  MaktubGenerationNum_perform(MaktubGenerationNum *self);

double  MaktubGenerationNum_get_probability_num(MaktubGenerationNum *self,int index);

void private_MaktubGenerationNum_free(MaktubGenerationNum *self);



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


MakTubeStringArray * newMakTubeStringArray();

void MakTubeStringArray_append(MakTubeStringArray *self,const char *item);

int  MakTubeStringArray_get_size(MakTubeStringArray *self);

const char * MakTubeStringArray_get_str(MakTubeStringArray *self,int index);

void MakTubeStringArray_free(MakTubeStringArray *self);



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


long long MakTube_generate_random_num_based_on_seed(
    unsigned long long  seed,
    long long min,
    long long max
);



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

MakTubeStringArrayNamespace newMakTubeStringArrayNamespace();



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


GenerationActionNamespace newGenerationActionNamespace();



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


GenerationNumNamespace newGenerationNumNamespace();



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

MakTubNamespace newMakTubNameskace();



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


MakTubSequencialsNamespace newMakTubSequencialsNamespace();


#endif


#ifndef maktub_fdefine
#define maktub_fdefine

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


MakTubeGenerationAction * private_newMakTubeGenerationAction(MakTub *Maktube_obj){
    MakTubeGenerationAction *self = (MakTubeGenerationAction*)malloc(sizeof(MakTubeGenerationAction));
    *self = (MakTubeGenerationAction){0};
    self->root_obj = Maktube_obj;
    self->nums = private_new_MaktubGenerationNum(Maktube_obj);
    return self;
}

void MakTubeGenerationAction_subscribe_function(
    MakTubeGenerationAction *self,
    double chance,
    void (*generation_callback)(MakTub *item)
){
    MaktubGenerationNum_add_probability(self->nums,chance);
    self->actions[self->size_actions].generation_callback =  (void (*)(void *))generation_callback;
    self->size_actions+=1;
}

void MakTubeGenerationAction_perform(MakTubeGenerationAction *self){
     self->root_obj->index = MaktubGenerationNum_perform(self->nums);

     if(self->root_obj->index == -1){
        return;
     }

     void * old_args = self->root_obj->current_args;
     self->root_obj->probability = MaktubGenerationNum_get_probability_num(self->nums,self->root_obj->index);
     self->actions[self->root_obj->index].generation_callback((void*)self->root_obj);
     self->root_obj->current_args = old_args;
}



void private_free_MakTubeGenerationAction(MakTubeGenerationAction *self){
private_MaktubGenerationNum_free(self->nums);
free(self);
}



//silver_chain_scope_start
//mannaged by silver chain


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

char * MakTub_get_seed(MakTub *self){
    return  self->seed;
}
int MakTub_get_generation(MakTub *self){
    return self->generation;
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
    private_MakTub_generate_num_seed(self);
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
    MakTubeStringArray * itens = newMakTubeStringArray();
    UniversalGarbage_add(self->garbage,MakTubeStringArray_free, itens);

    for(int k = 0; k < max_try; k++){

        if(itens->size >= max_itens){
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



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end



MaktubGenerationNum * private_new_MaktubGenerationNum(MakTub *Maktub_obj){
    MaktubGenerationNum *self = (MaktubGenerationNum*)malloc(sizeof(MaktubGenerationNum));
    *self = (MaktubGenerationNum){0};
    self->root_obj = Maktub_obj;
    return self;
}

int MaktubGenerationNum_add_probability(MaktubGenerationNum *self,double chance){
    if(self->size_chanches >=  MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA){
        return -1;
    }
    self->chances[self->size_chanches] = chance;
    int position = self->size_chanches;
    self->size_chanches+=1;
    return position;
}
void private_MaktubGenerationNum_generate_prediction(MaktubGenerationNum *self){
    double total_sum =0;
    int total_skkiped  = 0;
    for(int i =0; i<self->size_chanches;i++){
        if(self->chances[i] == -1){
            total_skkiped+=1;
            continue;
        }
        total_sum+=self->chances[i];
    }
    double rest = 1 - total_sum;
    double division = 0;
    if(rest > 0  && total_skkiped >0){
         division = (rest /total_skkiped);
    }

    for(int i =0; i<self->size_chanches;i++){
        if(self->chances[i] == -1){
            self->chances[i] = division;
        }
    }
}
double  MaktubGenerationNum_get_probability_num(MaktubGenerationNum *self,int index){
    if(index > self->size_chanches){
        return -1;
    }
    return self->chances[index];
}

int  MaktubGenerationNum_perform(MaktubGenerationNum *self){
    private_MaktubGenerationNum_generate_prediction(self);
    int chosed = Maktub_generate_num(self->root_obj, 1, MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA);
    for(int i = 0; i < self->size_chanches;i++){
        int current_chance = (self->chances[i] * MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA)* (i+1);

        if(chosed <= current_chance){
            return i;
        }
    }

    return -1;
}

void private_MaktubGenerationNum_free(MaktubGenerationNum *self){
    free(self);
}



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

MakTubeStringArray * newMakTubeStringArray(){
    MakTubeStringArray *self = (MakTubeStringArray*)malloc(sizeof(MakTubeStringArray));
    self->itens = (char**)malloc(1);
    self->allocated_size = 1;
    self->size = 0;
    return self;
}

void MakTubeStringArray_append(MakTubeStringArray *self,const char *item){

    long required_size = (self->size+1) * sizeof(char**);
    if(self->allocated_size <= required_size) {
        self->itens = (char**)realloc(self->itens, required_size * 3);
    }
    self->itens[self->size] = strdup(item);
    self->size+=1;
}

int  MakTubeStringArray_get_size(MakTubeStringArray *self){
    return self->size;
}

const char * MakTubeStringArray_get_str(MakTubeStringArray *self,int index){
    if(index >= self->size){
        return NULL;
    }
    return self->itens[index];
}

void MakTubeStringArray_free(MakTubeStringArray *self){
    for(int i = 0; i < self->size;i++){
        free(self->itens[i]);
    }
    free(self->itens);
    free(self);
}



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

long long MakTube_generate_random_num_based_on_seed(
    unsigned long long  seed,
    long long min,
    long long max
){
    /*
    srand(seed);
    unsigned int result = rand();
    */

    unsigned long long result = seed + MAKTUB_PI;

    for(int i = 0; i < MAKTUBE_SUFFLE; i++){
        while (result < MAKTUB_MAX_SEED){
            result *= MAKTUBE_FACTOR;
            result +=i;
        }
        result = result % MAKTUB_MAX_SEED;
    }

    max+=1;
    max -= min;
    result = result % max;
    result+=min;
    return  result;
}



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

MakTubeStringArrayNamespace newMakTubeStringArrayNamespace(){
    MakTubeStringArrayNamespace self = {0};
    self.newStringArray =newMakTubeStringArray;
    self.append =MakTubeStringArray_append;
    self.get_size = MakTubeStringArray_get_size;
    self.get_str = MakTubeStringArray_get_str;
    self.free = MakTubeStringArray_free;
    return self;
}



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


GenerationActionNamespace newGenerationActionNamespace(){
    GenerationActionNamespace self = {0};
    self.subscribe_function =  MakTubeGenerationAction_subscribe_function;
    self.perform = MakTubeGenerationAction_perform;
    return self;
}



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


GenerationNumNamespace newGenerationNumNamespace(){
    GenerationNumNamespace self = {0};
    self.add_probability= MaktubGenerationNum_add_probability;
    self.perform =   MaktubGenerationNum_perform;
    self.get_probability_num =  MaktubGenerationNum_get_probability_num;
    return self;
}




//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

MakTubNamespace newMakTubNameskace(){
    MakTubNamespace self = {0};
    self.get_generation = MakTub_get_generation;
    self.newMakTub=  newMakTub;
    self.get_seed = MakTub_get_seed;

    self.set_generation = MakTub_set_generation;
    self.set_seed = MakTub_set_seed;
    self.aply_seed_modification = MakTub_aply_seed_modification;
    self.generate_num = Maktub_generate_num;
    self.newGenerationNum = MakTub_newGenerationNum;
    self.newGenerationAction = MakTub_newGenerationAction;
    self.generate_choice = Maktub_generate_choice;
    self.generate_token = MakTub_generate_token;
    self.aply_seed_modification_returning_string_array= Maktube_aply_seed_modification_returning_string_array;
    self.aply_seed_modification_til_find = Maktube_aply_seed_modification_til_find;
    self.free =  MakTub_free;
    self.num =newGenerationNumNamespace();
    self.actions = newGenerationActionNamespace();
    self.seqs = newMakTubSequencialsNamespace();
    self.string_array = newMakTubeStringArrayNamespace();
    return self;

}



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end
MakTubSequencialsNamespace newMakTubSequencialsNamespace() {
    MakTubSequencialsNamespace self = {0};
    self.numbers = MAKTUBE_NUMBERS;
    self.uppercase = MAKTUBE_UPPERCASE;
    self.lowercase = MAKTUBE_LOWERCASE;
    self.lowercase_num = MAKTUBE_LOWERCASE_NUM;
    self.uppercase_num = MAKTUBE_UPPERCASE_NUM;
    self.allpha_nuns = MAKTUBE_ALFHA_NUNS;
    return self;
}


#endif


#endif

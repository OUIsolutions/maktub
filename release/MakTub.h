
#ifndef MAKTUB_H
#define MAKTUB_H
#ifndef silverchain_native
#define silverchain_native
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#endif


#ifndef silverchain_dependency
#define silverchain_dependency

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


#ifndef silverchain_consts
#define silverchain_consts

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

#define MAKTUB_DEFAULT_SEED_FACTOR 2
#define MAKTUB_DEFAULT_NUM_FACTOR 2
#define MAKTUB_DEFAULT_START_MULTIPLYER 2
#define MAKTUB_DEFAULT_NUM_MULTIPLYER 2


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


#endif


#ifndef silverchain_struct
#define silverchain_struct

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


typedef struct MakTub
{
   const char *seed;
   unsigned long long num_seed;
   UniversalGarbage *garbage;
   bool started;
   short seed_factor;
   short num_factor;
   short num_multiplier;
   short start_multiplier;

   int generation;

   void *static_args;
   void *current_args;
   int index;
   double probability;

}MakTub;


#endif


#ifndef silverchain_structB
#define silverchain_structB

//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end



typedef struct MaktubGenerationNum{
    MakTub *root_obj;
    double chances[MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA];
    int size_chanches;

}MaktubGenerationNum;


#endif


#ifndef silverchain_structC
#define silverchain_structC

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


#ifndef silverchain_structD
#define silverchain_structD

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

typedef struct MakTubNameskace{
    MakTub * (*newMakTub)(const char *seed);
    int  (*generate_num)(MakTub *self,  int min,  int  max);
    MaktubGenerationNum * (*newGenerationNum)(MakTub *self);
    MakTubeGenerationAction * (*newGenerationAction)(MakTub *self);
    void * (*generate_choice)(MakTub *self,void **elements,int elements_size);
    char * (*generate_token)(MakTub *self ,int token_size,const char *valid_chars);
    GenerationNumNamespace num;
    GenerationActionNamespace actions;
    

void (*free)(MakTub *self);

}MakTubNameskace;

#endif


#ifndef silverchain_fdeclare
#define silverchain_fdeclare

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



MakTub * newMakTub(const char *seed);

void private_MakTub_start(MakTub *self);

int  Maktub_generate_num(MakTub *self,  int min,  int  max);

MaktubGenerationNum * MakTub_newGenerationNum(MakTub *self);

MakTubeGenerationAction * MakTub_newGenerationAction(MakTub *self);

void * Maktub_generate_choice(MakTub *self,void **elements,int elements_size);


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


GenerationActionNamespace newGenerationActionNamespace();



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end


GenerationNumNamespace newGenerationNumNamespace();



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end

MakTubNameskace newMakTubNameskace();

#endif


#ifndef silverchain_fdefine
#define silverchain_fdefine

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
    MaktubGenerationNum *obj= private_new_MaktubGenerationNum(self);
    UniversalGarbage_add(self->garbage,private_MaktubGenerationNum_free,obj);
    return obj;

}
MakTubeGenerationAction * MakTub_newGenerationAction(MakTub *self){
    MakTubeGenerationAction *obj = private_newMakTubeGenerationAction(self);
    UniversalGarbage_add(self->garbage,private_free_MakTubeGenerationAction,obj);
    return obj;
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

    min-=1;
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
    result = result % max+1;
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
void MakTub_free(MakTub *self){
    UniversalGarbage_free(self->garbage);
    free(self);
}



//silver_chain_scope_start
//mannaged by silver chain


//silver_chain_scope_end



MaktubGenerationNum * private_new_MaktubGenerationNum(MakTub *Maktub_obj){
    MaktubGenerationNum *self = (MaktubGenerationNum*)malloc(sizeof(MaktubGenerationNum));
    self->root_obj = Maktub_obj;
    return self;
}

int MaktubGenerationNum_add_probability(MaktubGenerationNum *self,double chance){
    if(self->size_chanches >=  MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA){
        return MAKTUB_MAX_CHANCES;
    }
    self->chances[self->size_chanches] = chance;
    self->size_chanches+=1;
    return 0;
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

MakTubNameskace newMakTubNameskace(){
    MakTubNameskace self = {0};
    
    self.newMakTub=  newMakTub;
    self.generate_num = Maktub_generate_num;
    self.newGenerationNum = MakTub_newGenerationNum;
    self.newGenerationAction = MakTub_newGenerationAction;
    self.generate_choice = Maktub_generate_choice;
    self.generate_token = MakTub_generate_token;
    self.free =  MakTub_free;
    self.num =newGenerationNumNamespace();
    self.actions = newGenerationActionNamespace();
    return self;

}

#endif


#endif

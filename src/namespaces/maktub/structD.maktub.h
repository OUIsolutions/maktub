
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.structC.h"
//silver_chain_scope_end

typedef struct MakTubNameskace{


    MaktubGenerationNum * (*set_generation)(MakTub *self,int generation);
    void (*set_seed)(MakTub *self,const char *seed,...);
    void (*aply_seed_modification)(MakTub *self,int points[], int point_sizes,const char *valid_chars);
    MakTub * (*newMakTub)(const char *seed,...);
    int  (*generate_num)(MakTub *self,  int min,  int  max);
    MaktubGenerationNum * (*newGenerationNum)(MakTub *self);
    MakTubeGenerationAction * (*newGenerationAction)(MakTub *self);
    void * (*generate_choice)(MakTub *self,void **elements,int elements_size);
    char * (*generate_token)(MakTub *self ,int token_size,const char *valid_chars);
    GenerationNumNamespace num;
    GenerationActionNamespace actions;


void (*free)(MakTub *self);

}MakTubNameskace;

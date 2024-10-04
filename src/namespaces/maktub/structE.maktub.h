
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.structD.h"
//silver_chain_scope_end

typedef struct MakTubNamespace{


    void(*set_generation)(MakTub *self,int generation);
    void (*set_seed)(MakTub *self,const char *seed,...);
    void (*aply_seed_modification)(MakTub *self,int points[], int point_sizes,const char *valid_chars);
    MakTub * (*newMakTub)(const char *seed,...);
    long long   (*generate_num)(MakTub *self,  long long  min,  long long   max);
    MaktubGenerationNum * (*newGenerationNum)(MakTub *self);
    MakTubeGenerationAction * (*newGenerationAction)(MakTub *self);
    void * (*generate_choice)(MakTub *self,void **elements,int elements_size);
    char * (*generate_token)(MakTub *self ,int token_size,const char *valid_chars);

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

void (*free)(MakTub *self);

}MakTubNamespace;

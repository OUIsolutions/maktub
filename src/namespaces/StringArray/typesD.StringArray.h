
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesC.h"
//silver_chain_scope_end
typedef struct MakTubeStringArrayNamespace{

    MakTubeStringArray * (*newStringArray)();
    void (*append)(MakTubeStringArray *self,const char *item);
    int  (*get_size)(MakTubeStringArray *self);
    const char * (*get_str)(MakTubeStringArray *self,int index);

    void (*free)(MakTubeStringArray *self);

} MakTubeStringArrayNamespace;

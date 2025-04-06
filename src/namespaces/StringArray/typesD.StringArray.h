
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.structC.h"
//silver_chain_scope_end
typedef struct MakTubeStringArrayNamespace{

    MakTubeStringArray * (*newStringArray)();
    void (*append)(MakTubeStringArray *self,const char *item);
    int  (*get_size)(MakTubeStringArray *self);
    const char * (*get_str)(MakTubeStringArray *self,int index);

    void (*free)(MakTubeStringArray *self);

} MakTubeStringArrayNamespace;

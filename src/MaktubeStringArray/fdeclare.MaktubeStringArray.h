
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.structE.h"
//silver_chain_scope_end


MakTubeStringArray * newMakTubeStringArray();

void MakTubeStringArray_append(MakTubeStringArray *self,const char *item);

int  MakTubeStringArray_get_size(MakTubeStringArray *self);

const char * MakTubeStringArray_get_str(MakTubeStringArray *self,int index);

void MakTubeStringArray_free(MakTubeStringArray *self);

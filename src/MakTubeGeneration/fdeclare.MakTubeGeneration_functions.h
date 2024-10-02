
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.structB.h"
//silver_chain_scope_end


MakTubeGeneration * private_newMakTubeGeneration(MakTub *Maktube_obj);

void MakTubeGeneration_subscribe_function(MakTubeGeneration *self,double chance, void (*generation_callback)(MakTub *item));

void MakTubeGeneration_perform(MakTub *self);

void private_free_MakTubeGeneration(MakTubeGeneration *self);

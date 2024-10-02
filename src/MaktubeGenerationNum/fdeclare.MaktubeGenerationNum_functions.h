
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.structB.h"
//silver_chain_scope_end



MaktubGenerationNum * private_new_MaktubGenerationNum(MakTub *Maktub_obj);


int MaktubGenerationNum_add_probability(MaktubGenerationNum *self,double chance);

int  MaktubGenerationNum_perform(MaktubGenerationNum *self);


void private_MaktubGenerationNum_free(MaktubGenerationNum *self);

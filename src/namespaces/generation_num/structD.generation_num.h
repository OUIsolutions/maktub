
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.structC.h"
//silver_chain_scope_end


typedef struct  GenerationNumNamespace{
   

int (*add_probability)(MaktubGenerationNum *self,double chance);
int  (*perform)(MaktubGenerationNum *self);
double  (*get_probability_num)(MaktubGenerationNum *self,int index);


}GenerationNumNamespace;

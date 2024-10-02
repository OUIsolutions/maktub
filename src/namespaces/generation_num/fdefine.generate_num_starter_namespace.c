
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.fdeclare.h"
//silver_chain_scope_end


GenerationNumNamespace newGenerationNumNamespace(){
    GenerationNumNamespace self = {0};
    self.add_probability= MaktubGenerationNum_add_probability;
    self.perform =   MaktubGenerationNum_perform;
    self.get_probability_num =  MaktubGenerationNum_get_probability_num;
    return self;
}


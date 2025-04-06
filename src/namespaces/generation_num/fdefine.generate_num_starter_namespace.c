
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dep_define.h"
//silver_chain_scope_end


GenerationNumNamespace newGenerationNumNamespace(){
    GenerationNumNamespace self = {0};
    self.add_probability= MaktubGenerationNum_add_probability;
    self.perform =   MaktubGenerationNum_perform;
    self.get_probability_num =  MaktubGenerationNum_get_probability_num;
    return self;
}


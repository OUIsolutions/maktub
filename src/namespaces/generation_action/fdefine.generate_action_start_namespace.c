
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dep_define.h"
//silver_chain_scope_end


GenerationActionNamespace newGenerationActionNamespace(){
    GenerationActionNamespace self = {0};
    self.subscribe_function =  MakTubeGenerationAction_subscribe_function;
    self.perform = MakTubeGenerationAction_perform;
    return self;
}

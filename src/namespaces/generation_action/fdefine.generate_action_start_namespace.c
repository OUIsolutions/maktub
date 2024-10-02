
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.fdeclare.h"
//silver_chain_scope_end


GenerationActionNamespace newGenerationActionNamespace(){
    GenerationActionNamespace self = {0};
    self.subscribe_function =  MakTubeGenerationAction_subscribe_function;
    self.perform = MakTubeGenerationAction_perform;
    return self;
}


//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesC.h"
//silver_chain_scope_end




typedef struct GenerationActionNamespace{


    void (*subscribe_function)(
        MakTubeGenerationAction *self,
        double chance,
        void (*generation_callback)(MakTub *item)
    );

    void (*perform)(MakTubeGenerationAction *self);

}GenerationActionNamespace;
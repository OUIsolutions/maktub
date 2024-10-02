
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.structC.h"
//silver_chain_scope_end




typedef struct GenerationActionNamespace{


    void (*subscribe_function)(
        MakTubeGenerationAction *self,
        double chance,
        void (*generation_callback)(MakTub *item)
    );

    void (*perform)(MakTubeGenerationAction *self);

}GenerationActionNamespace;
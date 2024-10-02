
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.structC.h"
//silver_chain_scope_end


MakTubeGenerationAction * private_newMakTubeGenerationAction(MakTub *Maktube_obj);


void MakTubeGenerationAction_subscribe_function(
    MakTubeGenerationAction *self,
    double chance,
    void (*generation_callback)(MakTub *item)
);


void MakTubeGenerationAction_perform(MakTubeGenerationAction *self);




void private_free_MakTubeGenerationAction(MakTubeGenerationAction *self);

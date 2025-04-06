
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.typesE.h"
//silver_chain_scope_end


MakTubeGenerationAction * private_newMakTubeGenerationAction(MakTub *Maktube_obj);


void MakTubeGenerationAction_subscribe_function(
    MakTubeGenerationAction *self,
    double chance,
    void (*generation_callback)(MakTub *item)
);


void MakTubeGenerationAction_perform(MakTubeGenerationAction *self);




void private_free_MakTubeGenerationAction(MakTubeGenerationAction *self);

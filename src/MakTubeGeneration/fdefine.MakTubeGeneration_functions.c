
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end


MakTubeGenerationAction * private_newMakTubeGenerationAction(MakTub *Maktube_obj){
    MakTubeGenerationAction *self = (MakTubeGenerationAction*)malloc(sizeof(MakTubeGenerationAction));
    *self = (MakTubeGenerationAction){0};
    self->root_obj = Maktube_obj;
    self->nums = private_new_MaktubGenerationNum(Maktube_obj);
    return self;
}

void MakTubeGenerationAction_subscribe_function(MakTubeGenerationAction *self,double chance, void (*generation_callback)(MakTub *item)){
    MaktubGenerationNum_add_probability(self->nums,chance);
    self->actions[self->size_actions].generation_callback =  (void (*)(void *))generation_callback;
    self->size_actions+=1;
}

void MakTubeGenerationAction_perform(MakTubeGenerationAction *self){
     self->index = MaktubGenerationNum_perform(self->nums);
     void * old_args = self->current_args;
     self->probability = MaktubGenerationNum_get_probability_num(self->nums,self->index);
     self->actions[self->index].generation_callback((void*)self);
     self->current_args = old_args;
}

MakTubeGenerationAction * MakTubeGenerationAction_sub_generation(MakTubeGenerationAction *self){
    return private_newMakTubeGenerationAction(self->root_obj);
}

void private_free_MakTubeGenerationAction(MakTubeGenerationAction *self){
    private_MaktubGenerationNum_free(self->nums);
    free(self);
}

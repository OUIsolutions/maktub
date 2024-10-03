
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

void MakTubeGenerationAction_subscribe_function(
    MakTubeGenerationAction *self,
    double chance,
    void (*generation_callback)(MakTub *item)
){
    MaktubGenerationNum_add_probability(self->nums,chance);
    self->actions[self->size_actions].generation_callback =  (void (*)(void *))generation_callback;
    self->size_actions+=1;
}

void MakTubeGenerationAction_perform(MakTubeGenerationAction *self){
     self->root_obj->index = MaktubGenerationNum_perform(self->nums);

     if(self->root_obj->index == -1){
        return;
     }

     void * old_args = self->root_obj->current_args;
     self->root_obj->probability = MaktubGenerationNum_get_probability_num(self->nums,self->root_obj->index);
     self->actions[self->root_obj->index].generation_callback((void*)self->root_obj);
     self->root_obj->current_args = old_args;
}



void private_free_MakTubeGenerationAction(MakTubeGenerationAction *self){
private_MaktubGenerationNum_free(self->nums);
free(self);
}

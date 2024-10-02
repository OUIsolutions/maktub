
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end



MaktubGenerationNum * private_new_MaktubGenerationNum(MakTub *Maktub_obj){
    MaktubGenerationNum *self = (MaktubGenerationNum*)malloc(sizeof(MaktubGenerationNum));
    self->Maktub_obj = Maktub_obj;
    return self;
}

void MaktubGenerationNum_add_probability(MaktubGenerationNum *self,double chance){
    if(self->size_chanches >=  MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA){
        return ;
    }
    self->chances[self->size_chanches] = chance;
}

int  MaktubGenerationNum_perform(MaktubGenerationNum *self){

    int chosed = Maktub_generate_num((MakTub*)self->Maktub_obj, 1, MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA);
    printf("%d\n",chosed);
    for(int i = 0; i < self->size_chanches;i++){
        int current_chance = (self->chances[i] * MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA) * i+1;

        if(chosed <= current_chance){
            return i;
        }
    }

    return -1;
}

void private_MaktubGenerationNum_free(MaktubGenerationNum *self){
    free(self);
}

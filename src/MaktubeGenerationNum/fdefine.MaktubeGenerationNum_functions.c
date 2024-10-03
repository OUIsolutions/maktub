
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end



MaktubGenerationNum * private_new_MaktubGenerationNum(MakTub *Maktub_obj){
    MaktubGenerationNum *self = (MaktubGenerationNum*)malloc(sizeof(MaktubGenerationNum));
    *self = (MaktubGenerationNum){0};
    self->root_obj = Maktub_obj;
    return self;
}

int MaktubGenerationNum_add_probability(MaktubGenerationNum *self,double chance){
    if(self->size_chanches >=  MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA){
        return MAKTUB_MAX_CHANCES;
    }
    self->chances[self->size_chanches] = chance;
    self->size_chanches+=1;
    return 0;
}
void private_MaktubGenerationNum_generate_prediction(MaktubGenerationNum *self){
    double total_sum =0;
    int total_skkiped  = 0;
    for(int i =0; i<self->size_chanches;i++){
        if(self->chances[i] == -1){
            total_skkiped+=1;
            continue;
        }
        total_sum+=self->chances[i];
    }
    double rest = 1 - total_sum;
    double division = 0;
    if(rest > 0  && total_skkiped >0){
         division = (rest /total_skkiped);
    }

    for(int i =0; i<self->size_chanches;i++){
        if(self->chances[i] == -1){
            self->chances[i] = division;
        }
    }
}
double  MaktubGenerationNum_get_probability_num(MaktubGenerationNum *self,int index){
    if(index > self->size_chanches){
        return -1;
    }
    return self->chances[index];
}

int  MaktubGenerationNum_perform(MaktubGenerationNum *self){
    private_MaktubGenerationNum_generate_prediction(self);
    int chosed = Maktub_generate_num(self->root_obj, 1, MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA);
    for(int i = 0; i < self->size_chanches;i++){
        int current_chance = (self->chances[i] * MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA)* (i+1);

        if(chosed <= current_chance){
            return i;
        }
    }

    return -1;
}

void private_MaktubGenerationNum_free(MaktubGenerationNum *self){
    free(self);
}

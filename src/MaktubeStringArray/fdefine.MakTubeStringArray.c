
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end

MakTubeStringArray * newMakTubeStringArray(){
    MakTubeStringArray *self = (MakTubeStringArray*)malloc(sizeof(MakTubeStringArray));
    self->itens = (char**)malloc(1);
    self->allocated_size = 1;
    self->size = 0;
    return self;
}

void MakTubeStringArray_append(MakTubeStringArray *self,const char *item){

    long required_size = (self->size+1) * sizeof(char**);
    if(self->allocated_size <= required_size) {
        self->itens = (char**)realloc(self->itens, required_size * 3);
    }
    self->itens[self->size] = strdup(item);
    self->size+=1;
}

int  MakTubeStringArray_get_size(MakTubeStringArray *self){
    return self->size;
}

const char * MakTubeStringArray_get_str(MakTubeStringArray *self,int index){
    if(index >= self->size){
        return NULL;
    }
    return self->itens[index];
}

void MakTubeStringArray_free(MakTubeStringArray *self){
    for(int i = 0; i < self->size;i++){
        free(self->itens[i]);
    }
    free(self->itens);
    free(self);
}

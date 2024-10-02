
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.structC.h"
//silver_chain_scope_end



MakTub * newMakTub(const char *seed);

void private_MakTub_start(MakTub *self);

int  Maktub_generate_num(MakTub *self,  int min,  int  max);

MaktubGenerationNum * MakTub_newGenerationNum(MakTub *self);

MakTubeGenerationAction * MakTub_newGenerationAction(MakTub *self);

void * Maktub_generate_choice(MakTub *self,void **elements,int elements_size);


char * MakTub_generate_token(MakTub *self ,int token_size,const char *valid_chars);

void MakTub_free(MakTub *self);

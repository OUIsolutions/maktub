
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.structD.h"
//silver_chain_scope_end



MakTub * newMakTub(const char *seed,...);

MaktubGenerationNum * MakTub_set_generation(MakTub *self,int generation);

void MakTub_aply_seed_modification(MakTub *self,int points[], int point_sizes,const char *valid_chars);


void private_MakTub_generate_num_seed(MakTub *self);

void private_Maktube_set_seed_by_vaarg(MakTub *self,const char *seed_fmt,va_list args);

void MakTub_set_seed(MakTub *self,const char *seed,...);

int  Maktub_generate_num(MakTub *self,  int min,  int  max);

MaktubGenerationNum * MakTub_newGenerationNum(MakTub *self);

MakTubeGenerationAction * MakTub_newGenerationAction(MakTub *self);

void * Maktub_generate_choice(MakTub *self,void **elements,int elements_size);


char * MakTub_generate_token(MakTub *self ,int token_size,const char *valid_chars);

void MakTub_free(MakTub *self);

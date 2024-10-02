
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.structC.h"
//silver_chain_scope_end


MakTub * newMakTub(const char *seed);

long  Maktub_generate_num(MakTub *self,unsigned  int min, unsigned int  max);

void * Maktub_choice(MakTub *self,void **elements,int elements_size);

char * MakTub_token(MakTub *self ,int token_size,const char *valid_chars);



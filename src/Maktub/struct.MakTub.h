
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.consts.h"
//silver_chain_scope_end


typedef struct MakTub
{
    char *seed;
   unsigned int   num_seed;
   UniversalGarbage *garbage;
   bool started;

   int generation;

   void *static_args;
   void *current_args;
   int index;
   double probability;

}MakTub;

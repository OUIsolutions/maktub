
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.consts.h"
//silver_chain_scope_end


typedef struct MakTub
{
   const char *seed;
   unsigned long long num_seed;
   UniversalGarbage *garbage;
   bool started;
   short seed_factor;
   short num_factor;
   short num_multiplier;
   short start_multiplier;

   int generation;

}MakTub;

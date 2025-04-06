
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.macros.h"
//silver_chain_scope_end


typedef struct MakTub
{

   struct MakTub *meta_object;
   char *seed;
   unsigned long long    num_seed;
   UniversalGarbage *garbage;
   bool started;

   int generation;

   void *static_args;
   void *current_args;
   int index;
   double probability;

}MakTub;

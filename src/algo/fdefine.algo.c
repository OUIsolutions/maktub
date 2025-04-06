
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dep_define.h"
//silver_chain_scope_end

long long MakTube_generate_random_num_based_on_seed(
    unsigned long long  seed,
    long long min,
    long long max
){
    /*
    srand(seed);
    unsigned int result = rand();
    */

    unsigned long long result = seed + MAKTUB_PI;

    for(int i = 0; i < MAKTUBE_SUFFLE; i++){
        while (result < MAKTUB_MAX_SEED){
            result *= MAKTUBE_FACTOR;
            result +=i;
        }
        result = result % MAKTUB_MAX_SEED;
    }

    max+=1;
    max -= min;
    result = result % max;
    result+=min;
    return  result;
}

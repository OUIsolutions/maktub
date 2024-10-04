
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end

long long MakTube_generate_random_num_based_on_seed(
    unsigned long long  seed,
    long long min,
    long long max
){


    unsigned long long result = seed + MAKTUB_PI;

    while (result < MAKTUB_MAX_SEED){
        result *= MAKTUBE_FACTOR;
    }
    result = result % MAKTUB_MAX_SEED;
    max -= min;
    result = result % max;
    result+=min;
    return  result;
}

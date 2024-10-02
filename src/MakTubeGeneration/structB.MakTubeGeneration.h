
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.struct.h"
//silver_chain_scope_end

typedef struct privateMakTubeAction{
    void (*generation_callback)(MakTub *item,double chance,int index);
}privateMakTubeAction;


typedef struct MakTubeGeneration{
 
    privateMakTubeAction actions[MAKTUB_GENERATION_PLOTAGE_AREA];
    int size_actions;
    
}MakTubeGeneration;
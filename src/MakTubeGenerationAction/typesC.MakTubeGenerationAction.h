
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.typesB.h"
//silver_chain_scope_end

typedef struct privateMakTubeAction{
    void (*generation_callback)(void *MakTubeGeneration);
}privateMakTubeAction;




typedef struct MakTubeGenerationAction{
    MakTub *root_obj;
    MaktubGenerationNum *nums;
    privateMakTubeAction actions[MAKTUB_DEFAULT_GENERATION_PLOTAGE_AREA];



    int size_actions;

}MakTubeGenerationAction;

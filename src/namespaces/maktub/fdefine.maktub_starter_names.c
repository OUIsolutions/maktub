
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.fdeclare.h"
//silver_chain_scope_end

MakTubNameskace newMakTubNameskace(){
    MakTubNameskace self = {0};

    self.newMakTub=  newMakTub;
    self.set_generation = MakTub_set_generation;
    self.set_seed = MakTub_set_seed;
    self.aply_seed_modification = MakTub_aply_seed_modification;
    self.generate_num = Maktub_generate_num;
    self.newGenerationNum = MakTub_newGenerationNum;
    self.newGenerationAction = MakTub_newGenerationAction;
    self.generate_choice = Maktub_generate_choice;
    self.generate_token = MakTub_generate_token;
    self.free =  MakTub_free;
    self.num =newGenerationNumNamespace();
    self.actions = newGenerationActionNamespace();
    return self;

}

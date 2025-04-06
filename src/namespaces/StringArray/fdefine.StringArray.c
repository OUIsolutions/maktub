
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dep_define.h"
//silver_chain_scope_end

MakTubeStringArrayNamespace newMakTubeStringArrayNamespace(){
    MakTubeStringArrayNamespace self = {0};
    self.newStringArray =newMakTubeStringArray;
    self.append =MakTubeStringArray_append;
    self.get_size = MakTubeStringArray_get_size;
    self.get_str = MakTubeStringArray_get_str;
    self.free = MakTubeStringArray_free;
    return self;
}

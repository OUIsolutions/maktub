
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.fdeclare.h"
//silver_chain_scope_end
MakTubSequencialsNamespace newMakTubSequencialsNamespace() {
    MakTubSequencialsNamespace self = {0};
    self.numbers = MAKTUBE_NUMBERS;
    self.uppercase = MAKTUBE_UPPERCASE;
    self.lowercase = MAKTUBE_LOWERCASE;
    self.lowercase_num = MAKTUBE_LOWERCASE_NUM;
    self.uppercase_num = MAKTUBE_UPPERCASE_NUM;
    self.allpha_nuns = MAKTUBE_ALFHA_NUNS;
    return self;
}

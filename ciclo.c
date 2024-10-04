#include "src/one.c"
#include "extra/doTheWorld.h"
#include "extra/CHashManipulator.h"
#include "tests/MakTub.h"
MakTubNamespace mak;
CHashNamespace chash;
DtwNamespace dtw;


int main(){

    // 8
   mak =newMakTubNameskace();
   chash = newCHashNamespace();
   dtw = newDtwNamespace();

   unsigned long long seed = 5321120;
   for(int i=0; i <1000;i++){
       int chose =MakTube_generate_random_num_based_on_seed(seed+i,0,MAKTUBE_ONE_BILION);
       printf("%d ",chose);
   }



}

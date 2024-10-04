#include "src/one.c"
#include "extra/doTheWorld.h"
#include "extra/CHashManipulator.h"
MakTubNameskace mak;
CHashNamespace chash;
DtwNamespace dtw;


int main(){

    // 8
   mak =newMakTubNameskace();
   chash = newCHashNamespace();
   dtw = newDtwNamespace();

   int nums[100] ={0};
   int num_size = sizeof(nums) / sizeof(int);
   unsigned long long seed = 5321120;
   for(int i=0; i <1000;i++){
       int chose =MakTube_generate_random_num_based_on_seed(seed+i,0,num_size-1);
       nums[chose]+=1;
   }

   for(int i =0; i <num_size;i++){
       int current = nums[i];
       if(current){
         printf("%d = %d\n",i,current);
       }
   }

}

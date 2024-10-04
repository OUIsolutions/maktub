#include "MakTub.h"
MakTubNamespace mak;

int main(){
    mak = newMakTubNameskace();
    MakTub * obj = mak.newMakTub("your seed here");
    int num = mak.generate_num(obj,0,100);
    printf("seed = %s\n",mak.get_seed(obj));
    printf("first =%d\n",num);
    mak.aply_seed_modification(obj,(int[]){0,1,2},3,mak.seqs.allpha_nuns);
    int num2 = mak.generate_num(obj,0,100);
    printf("seed = %s\n",mak.get_seed(obj));
    printf("second = %d\n",num2); //it will be equal to first
    mak.free(obj);
    return 0;
}

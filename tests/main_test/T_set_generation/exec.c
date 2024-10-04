#include "../../MakTub.h"
MakTubNamespace mak;

int main(){
    mak = newMakTubNameskace();
    MakTub * obj = mak.newMakTub("your seed here");
    int num = mak.generate_num(obj,0,100);
    printf("first =%d\n",num);
    mak.set_generation(obj,0);
    int num2 = mak.generate_num(obj,0,100);
    printf("second = %d\n",num2); //it will be equal to first
    mak.free(obj);
    return 0;
}

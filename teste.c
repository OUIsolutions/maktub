#include "src/one.c"

int main(){
    MakTub * test = newMakTub("aaa2m32m3i244b4");
    /*
    for(int i = 0; i < 100; i++){
        printf("%d\n",Maktub_generate_num(test, 0, 100));
    }
    */
    for(int i = 0; i < 100; i++){
        printf("%s\n",MakTub_generate_token(test,10,"ABCDEFGHJIJLKMN1234567890"));
    }
}

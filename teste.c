#include "src/one.c"

int main(){
    MakTub * test = newMakTub("aaa2m32m3i244b4");
    /*
    for(int i = 0; i < 100; i++){
        printf("%d\n",Maktub_generate_num(test, 0, 100));
    }
    */
    MaktubGenerationNum * m = MakTub_newGenerationNum(test);
    MaktubGenerationNum_add_probability(m, 0.1);
    MaktubGenerationNum_add_probability(m, 0.9);

    for(int i = 0; i < 100; i++){
        int index = MaktubGenerationNum_perform(m);
        printf("%d\n",index);
    }
}

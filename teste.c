#include "src/one.c"

int main(){
    MakTub * test = newMakTub("aaa2m32m3i244b4");
    /*
    for(int i = 0; i < 100; i++){
        printf("%d\n",Maktub_generate_num(test, 0, 100));
    }
    */
    MaktubGenerationNum * m = MakTub_newGenerationNum(test);
    MaktubGenerationNum_add_probability(m, 0.25);
    MaktubGenerationNum_add_probability(m, 0.25);
    MaktubGenerationNum_add_probability(m, -1);

    int index = MaktubGenerationNum_perform(m);

    int index_count[3] = {0};
    for(int i = 0; i < 10000; i++){
        int index = MaktubGenerationNum_perform(m);
        index_count[index]+=1;
    }
    for(int i=0;i < sizeof(index_count)/sizeof(int);i++){
        printf("%d= %d\n",i,index_count[i]);
    }
}

#include "src/one.c"
MakTubNameskace mak;


int main(){
   mak =newMakTubNameskace();
   MakTub * test = mak.newMakTub("aaa232m3i4sss");
   const char *t[] = {"aaa","aaa","ddd"};
    char *escolhido  = Maktub_generate_choice(test,(void**)t,sizeof(t)/sizeof(char*));
    printf("%s",escolhido);
   MakTub_free(test);
}

#include "src/one.c"
MakTubNameskace mak;


int main(){
   mak =newMakTubNameskace();
   MakTub * test = mak.newMakTub("aaaddssds232m3i4dddsss");

   
   const char *t[] = {"aaa","aaa","ddd","aaa","aaa"};
    char *escolhido  = mak.generate_choice(test,(void**)t,sizeof(t)/sizeof(char*));
    printf("%s",escolhido);
   MakTub_free(test);
}

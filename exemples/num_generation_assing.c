


/*
It is also possible to generate pseudo randomness in lists.
*/

#include "MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  MaktubGenerationNum *nuns = mak.newGenerationNum(obj);
  int first  = mak.num.add_probability(nuns,0.33);
  int second = mak.num.add_probability(nuns,0.33);
  int third = mak.num.add_probability(nuns,0.33);
  int result = mak.num.perform(nuns);
  if(result == first){
      printf("got first\n");
  }
  else if(result == second){
      printf("got second");
  }
  else if(result == third){
      printf("got third");
  }
  else {
      printf("got none\n");
  }

  mak.free(obj);
  return 0;
}

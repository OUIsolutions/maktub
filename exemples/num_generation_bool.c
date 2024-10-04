


/*
It is also possible to generate pseudo randomness in lists.
*/

#include "MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  MaktubGenerationNum *nuns = mak.newGenerationNum(obj);
  mak.num.add_probability(nuns,0.25);
  mak.num.add_probability(nuns,0.75);

  bool you_play_minecraft = mak.num.perform(nuns);
  if(you_play_minecraft){
      printf("you play minecraft\n");
  }
  if(!you_play_minecraft){
      printf("you dont play minecraft\n");
  }
  mak.free(obj);
  return 0;
}

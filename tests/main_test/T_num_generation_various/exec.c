


/*
It is also possible to generate pseudo randomness in lists.
*/

#include "../../MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  MaktubGenerationNum *nuns = mak.newGenerationNum(obj);
  mak.num.add_probability(nuns,0.25);
  mak.num.add_probability(nuns,0.25);
  mak.num.add_probability(nuns,-1); // will have 10%
  mak.num.add_probability(nuns,-1); // will have 10%
  mak.num.add_probability(nuns,-1); // will have 10%
  mak.num.add_probability(nuns,-1); // will have 10%
  mak.num.add_probability(nuns,-1); // will have 10%

  printf("chosed alternative %d",mak.num.perform(nuns));
  mak.free(obj);
  return 0;
}

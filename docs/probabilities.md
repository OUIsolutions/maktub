
## Probabilities
you can set probabilities for for switching elements

~~~c

#include "MaktubOne.c"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  MaktubGenerationNum *nuns = mak.newGenerationNum(obj);
  mak.num.add_probability(nuns,0.33);
  mak.num.add_probability(nuns,0.33);
  mak.num.add_probability(nuns,0.33);

  printf("chosed alternative %d",mak.num.perform(nuns));
  mak.free(obj);
  return 0;
}

~~~



its also possible to use it at a boolean strategy

~~~c

#include "MaktubOne.c"

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

~~~

if you prever a more **safer aproach**  you can use like these

~~~c

#include "MaktubOne.c"

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

~~~

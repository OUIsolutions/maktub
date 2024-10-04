


/*
It is also possible to generate pseudo randomness in lists.
*/

#include "../../MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  const char *list[] = {"chaves", "Dona Florinda", "Shr. Girafales", "Nhonho"};

  const char *chosen_person = (char*)mak.generate_choice(obj, (void **)list, sizeof(list) / sizeof(char *));

  printf("\n\tchose person: %s\n", chosen_person);

  mak.free(obj);

  return 0;
}

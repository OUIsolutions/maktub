

/*
With MakTup you can generate tokens through seeds, choosing the number of characters and which characters are accepted.
*/

#include "../../MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  char *token = mak.generate_token(obj,10,"ABCDEFGHIJLMNQ");
  printf("%s\n",token);
  mak.free(obj);

  return 0;
}

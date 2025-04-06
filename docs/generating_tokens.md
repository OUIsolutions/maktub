
## Generating Tokens
you also can generate tokens of diferent sizes of diferent chars


~~~c


/*
With MakTup you can generate tokens through seeds, choosing the number of characters and which characters are accepted.
*/

#include "MaktubOne.c"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  char *token = mak.generate_token(obj,10,mak.seqs.allpha_nuns);
  printf("%s\n",token);
  mak.free(obj);

  return 0;
}

~~~

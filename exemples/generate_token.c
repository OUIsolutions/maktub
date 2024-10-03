

/*
With MakTup you can generate tokens through seeds, choosing the number of characters and which characters are accepted.
*/

#include "MakTub.h"

#define ACCEPTED_CARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz !@#$%*()"
#define NUMBER_OF_CARACTERS 12

MakTubNameskace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  const char *token_generated = ACCEPTED_CARACTERS; //mak.generate_token(obj, NUMBER_OF_CARACTERS, ACCEPTED_CARACTERS);
  
  printf("%s\n",token_generated);
  
  mak.free(obj);
  
  return 0;
}





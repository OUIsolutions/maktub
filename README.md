
## Maktub
Maktube its a pseudo randon generative library designed to generate
theorem tests, procedural objects constructions and anything that you need
pseudo random usage

## Install
These lib its designed to be as dumb as possible


## Quick Usage
these above example generates a simple rand number betwen  0 and 100


~~~c
#include "MakTub.h"
MakTubNamespace mak;

int main(){
    mak = newMakTubNameskace();
    MakTub * obj = mak.newMakTub("your seed here");
    int num = mak.generate_num(obj,0,100);
    printf("%d\n",num);
    mak.free(obj);
    return 0;
}

~~~

## Generating Tokens
you also can generate tokens of diferent sizes of diferent chars


~~~c


/*
With MakTup you can generate tokens through seeds, choosing the number of characters and which characters are accepted.
*/

#include "MakTub.h"

MakTubNamespace mak;

int main(){
  mak = newMakTubNameskace();

  MakTub * obj = mak.newMakTub("your seed here");

  char *token = mak.generate_token(obj,10,"ABCDEFGHIJLMNQ");
  printf("%s\n",token);
  mak.free(obj);

  return 0;
}

~~~

## Choice
you can choice betwen lists with generate choice functionality


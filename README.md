
## Maktub
Maktub its a pseudo randon generative library designed to generate
theorem tests, procedural objects constructions and anything that you need
pseudo random usage


## Release
|Item | Description| 
|-----|---|
|[Maktub.c](https://github.com/OUIsolutions/maktub/releases/download/0.5.0/Maktub.c)| Definition|
|[Maktub.h](https://github.com/OUIsolutions/maktub/releases/download/0.5.0/Maktub.h)| Header|
|[MaktubOne.c](https://github.com/OUIsolutions/maktub/releases/download/0.5.0/MaktubOne.c)|All in one|
|[Maktub.zip](https://github.com/OUIsolutions/maktub/releases/download/0.5.0/Maktub.zip)| Zip Folder|


## Quick Usage
these above example generates a simple rand number betwen  0 and 100
~~~c
#include "MaktubOne.c"
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

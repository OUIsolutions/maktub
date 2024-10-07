the answers:
Namespaces: they are not obrigatory, its not a POO simulation, the nasmpaces struct , it's just a intelisense facilitation , you can code fully without if you want
```c
#include "MakTub.h"
int main(){
    MakTub * mak_obj = newMakTub("your seed");
    int num  = Maktub_generate_num(mak_obj, 0, 100);
    printf("%d\n",num);
    MakTub_free(mak_obj);
}
```

about allocation:
The lib its not just for numbers, and choice, it also  for generate tokens and seed finders, in these case its better have a arena alocation to avoid leak memorys
```c
#include "MakTub.h"
MakTubNamespace mak;

int main(){
    mak = newMakTubNameskace();
    MakTub * obj = mak.newMakTub("your seed here");
    for(int i = 0; i < 10; i++){
        char *token = mak.generate_token(obj,10,mak.seqs.allpha_nuns);
        printf("%s\n",token);
    }
    mak.free(obj);
    return 0;
}
```
about the usage:, there is a lot of usage, generating passwords, generating fuzzing tests (which its the use case of my company) , procedural generation for gaming, etc.
About RNG: I dont know what its RNG , I made a lot of tests, and implement the most randon algo I could make, just it, you can see the pure algo without any container association in **src/algo/fdefine.algo.c**
```c

long long MakTube_generate_random_num_based_on_seed(
    unsigned long long  seed,
    long long min,
    long long max
){

    unsigned long long result = seed + MAKTUB_PI;

    for(int i = 0; i < MAKTUBE_SUFFLE; i++){
        while (result < MAKTUB_MAX_SEED){
            result *= MAKTUBE_FACTOR;
            result +=i;
        }
        result = result % MAKTUB_MAX_SEED;
    }

    max+=1;
    max -= min;
    result = result % max;
    result+=min;
    return  result;
}

```

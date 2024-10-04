
## Maktub
Maktube its a pseudo randon generative library designed to generate
theorem tests, procedural objects constructions and anything that you need
pseudo random usage

## Install
These lib its designed to be as dumb as possible,for usage just download the
[Amalgamation File](https://github.com/OUIsolutions/maktub/releases/download/v0.001/MakTub.h) int your project and include it directly into your main

```c
#include "MakTub.h"
int main(){
}
```


## Full Folder
you also can run the project directy from folder, just copy the **src** folder into
your project and include the **src/one.c** file into yout main
```c
#include "src/one.c"
int main(){

}

```
## Building From Scracth
if you want you can build from scracth the almagamation ,or work into the project
for builiding just run:
```sh
sh pre_build.sh && ./build.out
```
it will generate the amalgamation in **release** , and execute all the unit tests

#### SilverChain Path
these project uses [Silverchain](https://github.com/OUIsolutions/SilverChain) as
the default includer, and we recomen you to use, to a better development on files modification
for usage in these project, download silverchain and put the **silverchain binary**
into the main root dir, and run the sh **watch.sh** file


## Quick Usage
these above example generates a simple rand number betwen  0 and 100

codeof:exemples/rand_num.c

## Generating Tokens
you also can generate tokens of diferent sizes of diferent chars

codeof:exemples/generate_token.c

## Choice
you can choice betwen lists with generate choice functionality

codeof:exemples/generate_choice.c


## Probabilities
you can set probabilities for for switching elements
codeof:exemples/num_generation_basic.c

its also possible to use it at a boolean strategy
codeof:exemples/num_generation_bool.c

## Callbacks
you can determine a callback to be executed on each probability

codeof:exemples/subscribe_function.c

## Passing Args to callback
codeof:exemples/subscribe_function_passing_args.c


## Seed Control
all pseudo random numbers are generated based on the seed and on the
generation ,where you can modify and controll it

codeof:exemples/set_generation.c

## Making Seed random modifications
you can make small seed modifications to test varios hipoteses

codeof:exemples/seed_modify.c

### Finding Seed
you can find seed based on lambda blueprints and verifiers
codeof:exemples/seed_modify.c

### Finding many seeds
if you need you can find many seeds at once with string arrays


codeof:exemples/finding_string_array.c

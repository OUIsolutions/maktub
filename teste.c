#include "src/one.c"
#include "extra/doTheWorld.h"
#include "extra/CHashManipulator.h"
MakTubNameskace mak;
CHashNamespace chash;
DtwNamespace dtw;

typedef struct Props{
    CHash * obj;
    const char *chave;
    const char **lista;
    int size;
}Props;

void seta_como_nil(MakTub *args){
    Props  *props = (Props*)args->static_args;
    chash.object.set_any(props->obj,props->chave,chash.newNULL());
}

void seta_em_lista(MakTub *args){
    Props  *props = (Props*)args->static_args;
    char * escolhido = mak.generate_choice(args,(void**)props->lista,props->size);
    chash.object.set_any(props->obj,props->chave,chash.newString(escolhido));
}


void cria_json(int modificador){
   UniversalGarbage *lixo = newUniversalGarbage();
   MakTub * test = mak.newMakTub("podeserissoaqui%d.json",modificador);
   UniversalGarbage_add(lixo,mak.free,test);
   CHashObject *inicial = chash.object.newObjectEmpty();
   UniversalGarbage_add(lixo,chash.free,inicial);


   Props props  = {0};
   props.obj = inicial;
   props.chave = "nome";
   const char *lista[] = {"samuel","danilo","big samuel"};
   props.lista = lista;
   props.size  = sizeof(lista) / sizeof(char*);
   test->static_args = (void*)&props;

   MakTubeGenerationAction * nome = mak.newGenerationAction(test);
   mak.actions.subscribe_function(nome,0.10,seta_como_nil);
   mak.actions.subscribe_function(nome,0.80,seta_em_lista);
   mak.actions.perform(nome);

   MaktubGenerationNum *idade = mak.newGenerationNum(test);
   mak.num.add_probability(idade,0.3);
   mak.num.add_probability(idade,0.7);

   //retorna um index
   if(mak.num.perform(idade)){
       int sorteio = mak.generate_num(test,0,120);
       chash.object.set_long( inicial,"idade",sorteio);
   }


   char *dumped = chash.dump_to_json_string(inicial);
   UniversalGarbage_add_simple(lixo,dumped);

   char *caminho = dtw.concat_path("jsons_teses",test->seed);
   UniversalGarbage_add_simple(lixo, caminho);

   printf("gerado: %s\n",caminho);
   dtw.write_string_file_content(caminho,dumped);


   UniversalGarbage_free(lixo);
}

int main(){

   mak =newMakTubNameskace();
   chash = newCHashNamespace();
   dtw = newDtwNamespace();
   dtw.remove_any("jsons_teses");
   for(int i = 0; i < 100; i++){
      cria_json(i);
  }
  return 0;

}

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
    Props  *props = (Props*)args->current_args;
    chash.object.set_any(props->obj,props->chave,chash.newNULL());
}

void seta_em_lista(MakTub *args){
    Props  *props = (Props*)args->current_args;
    char * escolhido = mak.generate_choice(args,(void**)props->lista,props->size);
    chash.object.set_any(props->obj,props->chave,chash.newString(escolhido));
}


bool cria_json(MakTub *maktube_obj){
   UniversalGarbage *lixo = newUniversalGarbage();
   CHashObject *inicial = chash.object.newObjectEmpty();
   UniversalGarbage_add(lixo,chash.free,inicial);


   Props props  = {0};
   props.obj = inicial;
   props.chave = "nome";
   const char *lista[] = {"samuel","danilo","big samuel"};
   props.lista = lista;
   props.size  = sizeof(lista) / sizeof(char*);
   maktube_obj->current_args = (void*)&props;

   MakTubeGenerationAction * nome = mak.newGenerationAction(maktube_obj);
   mak.actions.subscribe_function(nome,0.10,seta_como_nil);
   mak.actions.subscribe_function(nome,0.80,seta_em_lista);
   mak.actions.perform(nome);

   MaktubGenerationNum *idade = mak.newGenerationNum(maktube_obj);
   mak.num.add_probability(idade,0.3);
   mak.num.add_probability(idade,0.7);

   //retorna um index
   if(mak.num.perform(idade)){
       int sorteio = mak.generate_num(maktube_obj,0,120);
       chash.object.set_long( inicial,"idade",sorteio);
   }

   char *dumped = chash.dump_to_json_string(inicial);
   UniversalGarbage_add_simple(lixo,dumped);

   DtwPath *caminho = dtw.path.newPath(maktube_obj->seed);
   UniversalGarbage_add(lixo,dtw.path.free, caminho);

   dtw.path.set_extension(caminho,".json");
   dtw.path.set_dir(caminho,"jsons_teses");
   if(dtw.entity_type(dtw.path.get_path(caminho))== DTW_FILE_TYPE){
       UniversalGarbage_free(lixo);
       return false;
   }
   dtw.write_string_file_content(dtw.path.get_path(caminho),dumped);


   UniversalGarbage_free(lixo);
   return true;
}

int main(){

    // 8
   mak =newMakTubNameskace();
   chash = newCHashNamespace();
   dtw = newDtwNamespace();
   dtw.remove_any("jsons_teses");
   MakTub *maktube_obj = mak.newMakTub("was644sd232sdsdasds22");
   int tota_creation = 0;
   for(int i = 0; i < 1000; i++){
       tota_creation+=cria_json(maktube_obj);
       mak.aply_seed_modification(maktube_obj,(int[]){0,1,2,3},4,"0123456789");
       if(tota_creation > 100){
           break;;
       }
   }
  printf("%d\n",tota_creation);
   mak.free(maktube_obj);
  return 0;

}

#include "src/one.c"

MakTubNameskace mak;

void imprime_nome(MakTub *main_obj){
    printf("nome: ");
    char *nomes[] = {"Pedro", "Maria"};
    char *escolhido = mak.generate_choice(main_obj, (void **) nomes, sizeof(nomes)/sizeof(char *));
    printf("%s", escolhido);
}

void imprime_nome_new(MakTub *main_obj){
    printf("nome: nill");

}

int main(){
    mak = newMakTubNameskace();
    MakTub *mak_ex = mak.newMakTub("ta324se");
    printf("Formulário n: \n");
    MakTubeGenerationAction *actions = mak.newGenerationAction(mak_ex);
    mak.actions.subscribe_function(actions,0.33,imprime_nome);
    mak.actions.subscribe_function(actions, 0.33,imprime_nome_new);
    mak.actions.perform(actions);
    mak.free(mak_ex);
}


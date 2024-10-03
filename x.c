#include "src/one.c"

MakTubNameskace mak;

void imprime_nome(MakTub *main_obj){
    printf("nome: ");
    const char *nomes[] = {"Pedro", "Maria"};
    char *escolhido = mak.generate_choice(main_obj, (void **)nomes, sizeof(nomes) /sizeof(char*));
    printf("%s\n", escolhido);

    
}

void imprime_nome_new(MakTub *main_obj){
    printf("nome: nill\n");

}
void imprimi_nada(MakTub *main_obj){

}
int main(){
    mak = newMakTubNameskace();
        for(int i=1 ; i < 10; i++){
        printf("iteracao: %d\n\n",i);
        MakTub *mak_ex = mak.newMakTub("dddssss");
        printf("Formulário n: \n");
        
       MakTubeGenerationAction *actions = mak.newGenerationAction(mak_ex);
        
       mak.actions.subscribe_function(actions,0.33,imprime_nome);
       
       mak.actions.subscribe_function(actions, 0.33,imprime_nome_new);
    
        printf("idade: %d\n",mak.generate_num(mak_ex,0,120));
        mak.actions.perform(actions);

        const char *pele[] = {"Branco", "Preto"};
        char *escolhido = mak.generate_choice(mak_ex, (void **)pele, sizeof(pele) /sizeof(char*));
        printf("pele: %s\n", escolhido);

        mak.free(mak_ex);
    
       }

  
}


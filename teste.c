#include "src/one.c"
MakTubNameskace mak;

void joga_minecraft(MakTub *root_obj){
    printf("e jogo minecraft");

}

void joga_poker(MakTub *root_obj){
    printf("e jogo poker");
}

void print_mateus(MakTub *root_obj){
    printf("mateus");
    MakTubeGenerationAction *action = mak.newGenerationAction(root_obj);
    mak.actions.subscribe_function(action,0.5, joga_poker);
    mak.actions.subscribe_function(action,0.5, joga_minecraft);
    mak.actions.perform(action);
}
void print_danilo(MakTub *root_obj){
    printf("danilo ");
}
void print_pocket(MakTub *root_obj){
    printf("pocket ");
    MakTubeGenerationAction *action = mak.newGenerationAction(root_obj);
    mak.actions.subscribe_function(action,0.5, joga_poker);
    mak.actions.subscribe_function(action,0.5, joga_minecraft);
   mak.actions.perform(action);
}

int main(){
    mak =newMakTubNameskace();
    MakTub * test = mak.newMakTub("aaa232m3i4sss");

    printf("meu nome é ");
    MakTubeGenerationAction *action = mak.newGenerationAction(test);
    mak.actions.subscribe_function(action,0.33, print_danilo);
    mak.actions.subscribe_function(action,0.33, print_mateus);
    mak.actions.subscribe_function(action,0.33, print_pocket);
    mak.actions.perform(action);
   MakTub_free(test);
}

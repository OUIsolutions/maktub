#include "src/one.c"
#include <stdbool.h>

void joga_minecraft(MakTub *root_obj){
    printf("e jogo minecraft");

}

void joga_poker(MakTub *root_obj){
    printf("e jogo poker");
}

void print_mateus(MakTub *root_obj){
    MakTubeGenerationAction *action = MakTub_newGenerationAction(root_obj);
    //MakTubeGenerationAction_subscribe_function(action,0.5, joga_poker);
    //MakTubeGenerationAction_subscribe_function(action,0.5, joga_minecraft);

}
void print_danilo(MakTub *root_obj){
    printf("danilo ");
}
void print_pocket(MakTub *root_obj){
    printf("pocket ");
    MakTubeGenerationAction *action = MakTub_newGenerationAction(root_obj);
   MakTubeGenerationAction_subscribe_function(action,0.5, joga_poker);
    MakTubeGenerationAction_subscribe_function(action,0.5, joga_minecraft);
    MakTubeGenerationAction_perform(action);
}

int main(){
    MakTub * test = newMakTub("aaa232m3i4ssss");

    printf("meu nome é ");
    MakTubeGenerationAction *action = MakTub_newGenerationAction(test);
    MakTubeGenerationAction_subscribe_function(action,0.33, print_danilo);
    MakTubeGenerationAction_subscribe_function(action,0.33, print_mateus);
    MakTubeGenerationAction_subscribe_function(action,0.33, print_pocket);
    MakTubeGenerationAction_perform(action);
   MakTub_free(test);
}

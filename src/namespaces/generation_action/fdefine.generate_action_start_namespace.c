


GenerationActionNamespace newGenerationActionNamespace(){
    GenerationActionNamespace self = {0};
    self.subscribe_function =  MakTubeGenerationAction_subscribe_function;
    self.perform = MakTubeGenerationAction_perform;
    return self;
}

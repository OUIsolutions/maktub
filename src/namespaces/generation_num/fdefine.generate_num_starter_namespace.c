


GenerationNumNamespace newGenerationNumNamespace(){
    GenerationNumNamespace self = {0};
    self.add_probability= MaktubGenerationNum_add_probability;
    self.perform =   MaktubGenerationNum_perform;
    self.get_probability_num =  MaktubGenerationNum_get_probability_num;
    return self;
}


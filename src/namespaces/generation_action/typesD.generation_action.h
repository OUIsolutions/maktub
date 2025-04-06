




typedef struct GenerationActionNamespace{


    void (*subscribe_function)(
        MakTubeGenerationAction *self,
        double chance,
        void (*generation_callback)(MakTub *item)
    );

    void (*perform)(MakTubeGenerationAction *self);

}GenerationActionNamespace;
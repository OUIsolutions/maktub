
typedef struct MakTubeStringArrayNamespace{

    MakTubeStringArray * (*newStringArray)();
    void (*append)(MakTubeStringArray *self,const char *item);
    int  (*get_size)(MakTubeStringArray *self);
    const char * (*get_str)(MakTubeStringArray *self,int index);

    void (*free)(MakTubeStringArray *self);

} MakTubeStringArrayNamespace;

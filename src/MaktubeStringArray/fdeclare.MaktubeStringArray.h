


MakTubeStringArray * newMakTubeStringArray();

void MakTubeStringArray_append(MakTubeStringArray *self,const char *item);

int  MakTubeStringArray_get_size(MakTubeStringArray *self);

const char * MakTubeStringArray_get_str(MakTubeStringArray *self,int index);

void MakTubeStringArray_free(MakTubeStringArray *self);

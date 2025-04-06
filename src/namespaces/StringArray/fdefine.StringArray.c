

MakTubeStringArrayNamespace newMakTubeStringArrayNamespace(){
    MakTubeStringArrayNamespace self = {0};
    self.newStringArray =newMakTubeStringArray;
    self.append =MakTubeStringArray_append;
    self.get_size = MakTubeStringArray_get_size;
    self.get_str = MakTubeStringArray_get_str;
    self.free = MakTubeStringArray_free;
    return self;
}

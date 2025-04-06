


typedef struct  GenerationNumNamespace{
   

int (*add_probability)(MaktubGenerationNum *self,double chance);
int  (*perform)(MaktubGenerationNum *self);
double  (*get_probability_num)(MaktubGenerationNum *self,int index);


}GenerationNumNamespace;

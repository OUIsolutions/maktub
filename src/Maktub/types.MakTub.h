


typedef struct MakTub
{

   struct MakTub *meta_object;
   char *seed;
   unsigned long long    num_seed;
   UniversalGarbage *garbage;
   bool started;

   int generation;

   void *static_args;
   void *current_args;
   int index;
   double probability;

}MakTub;

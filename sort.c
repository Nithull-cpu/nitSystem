#include "library.c"
#include "file_sys.h"

int swap_function(char *a, char *b);
int size = 1024;
int sort_loop_count = 0;
file_sys sort_ascending_function(char argv[]){
    char current_path[1024];
    getcwd(current_path, sizeof(current_path));
 char **sort_pointer = (char**) malloc(sizeof(char) * size);

 if(current_path != NULL){
    
 }
}
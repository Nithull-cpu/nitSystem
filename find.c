#include "file_sys.h"
#include "library.c"

file_sys find_folder(file_sys *f_point, char folder_name[], char file_name[]){

    if(access(folder_name, F_OK) == 0){
        char folder_path[255];
        char *dir_name = folder_name;
        char *file_name_f = file_name;

        // using the snprintf function to format this text if strings into an actual file_path
        snprintf(folder_path, sizeof(folder_path), "./%s/%s", dir_name, file_name_f);
        
    }else{
        perror("error");
        exit(EXIT_FAILURE);
    }
} 
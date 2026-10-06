#include "file_sys.h"
#include "library.c"
#define SIZE_FILE 1024

file_sys rename_function(char argv[], char argv1[]){
    // get our current active directory
        char current_path[1024];
        getcwd(current_path, sizeof(current_path));
    // check if it's the correct active directory that was been given to us
        if(current_path){
            // use the dir typedef in the dirent.h header file for ease file manipulation
            DIR *directory;
            // accessing the struct value in the dirent struct with our user defined pointer
            struct dirent *ent;

            char path[1024];
            strcpy(path, current_path);
            // opening our current directory
            directory = opendir(path);
            if(directory != NULL){
                if(access(argv, F_OK) == 0){
                    rename(argv, argv1);
                    perror("successfully renamed file");
                }else{
                    perror("\nerror");
                }
            }else{
                printf("error");
            }
        }

}
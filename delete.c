#include "file_sys.h"
#include "library.c"

int loop_count = 0;

file_sys delete_function( char argv[]){
  // malloced heap space for temporary values
  int dyn_size = 1024;
  char **pointer_file_name = (char**) malloc(sizeof(char)* dyn_size);
  // check for the folder or directory in our current directory
  char current_path[1024];
  getcwd(current_path, sizeof(current_path));

  if(current_path){
    DIR *directory;
    struct dirent *ent;
    char path[1024];
    strcpy(path, current_path);

    directory = opendir(path);
    if(directory != NULL){
      if(access(argv, F_OK) == 0){
        /* check to see if the intended folder to delete if empty
           and to navigate to the current directory we'll use the
           snpintf function to format the current directory to the current subdirectory
        */
       char sub_directory_path[1024];
       char *dir_name = current_path;
       char *sub_folder = argv;

        // using the snprintf function to format this text if strings into an actual file_path
        snprintf(sub_directory_path, sizeof(sub_directory_path), "%s\\%s", dir_name, sub_folder);
        if(sub_directory_path){
          // deleting the folder and checking if successfully deleted
          if(rmdir(sub_directory_path) == 0 || remove(argv) == 0){
            perror("successfully deleted content");
          }else{
            DIR *main_sub_directory;
            struct dirent *ent_sub;
            char sub_path[1024];
            strcpy(sub_path, sub_directory_path);
            main_sub_directory = opendir(sub_path);
            int sub_counter = 0;
            if(main_sub_directory != NULL){
              while ((ent_sub = readdir(main_sub_directory)) != NULL){
                //printf("%s\n", ent_sub->d_name);
                if(remove(ent_sub->d_name) == 0){
                  perror("successfully deleted folder content");
                }else{
                  sub_counter++;
                  for (int i = 0; i < sub_counter; i++){
                    pointer_file_name[i] = ent_sub[i].d_name;
          // format our string to a file path before permenant deletion using snprintf
                        char sub_dir_folder[255];
                        char *sub_dir_name = sub_path;
                        char *file_name_f = *pointer_file_name;
                        snprintf(sub_dir_folder, sizeof(sub_dir_folder), "%s\\%s", sub_dir_name, file_name_f);
          // actual deletion of the sub files in the sub directories and then deleting the sub directory itself
                      if(remove(sub_dir_folder) == 0 || rmdir(sub_dir_folder) == 0){
                        rmdir(sub_directory_path);
                        perror("successfully deleted folder");
                      }
                  }

                }
              }

            }
            
          }

      }else{
        perror("error locating current sub directory");
      }
      }else{
        perror("error");
      }
      closedir(directory);
    }
    
  }else{
    perror("error printing current directory");
  }
  free(pointer_file_name);
}  
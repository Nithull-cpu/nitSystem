#include "file_sys.h"
#include "library.c"



file_sys create_function(char argv[]){
    
    // dynamic heap memory for our file structure metadata
    file_sys *file_control = (file_sys*) malloc(sizeof(file_sys));
    // array for all the file extenions
    int size = 20;
    char **file_extensions = (char**) calloc(size, sizeof(char));
    // check to see our returned malloc block to avoid memory segmentation due to NULL pointer malloced
    if(file_control == NULL){
        perror("structure");
        exit(EXIT_FAILURE);
    }
    if(file_extensions == NULL){
        perror("extensions");
        exit(EXIT_FAILURE);
    }

    /* FOR FILE AND IT'S METADATA*/
    if(access(argv, F_OK) != 0){
        for(int i = 0; i < strlen(argv); ++i){
        //check if it's a file or directory(folder) using the "." symbol
            if(argv[i] == (char) (46)){
                // it's a valid file
                /* STORE METADATA INTO THE HEAP*/
                strcpy(file_control->file_name, argv);
                // we'll use the libmagic function to find the file type
                printf("%s\n", file_control->file_name);
                exit(EXIT_SUCCESS);
            }
        }
        /* FOR FOLDER AND IT'S METADATA*/
        for(int i = 0; i < strlen(argv); ++i){
            if(argv[i] != (char) 46){
                // it's a valid folder or directory type

                // store it's metadata into the heap
                strcpy(file_control->file_name, argv);
                printf("%s\n",file_control->file_name);

                strcpy(file_control->file_type, "Folder Type");
                printf("%s\n", file_control->file_type);

                file_control->permit = 0777;
                printf("%i\n", file_control->permit);

                file_control->file_flag = (int) "-c";
                printf("%d\n", file_control->file_flag);
                /* CREATING THE ACTUAL DIRECTORY USING THE MKDIR FUNCTION*/
                int fd = mkdir(file_control->file_name);

                //check if our directory was successfully created
                if(fd == 0){
                    perror("directory successfully created\n");
                    struct stat __dir__;
                    if(stat(file_control->file_name, &__dir__) == 0){
                        printf("it's working\n");
                        file_control->file_size = __dir__.st_size;
                        printf("%d KB\n", file_control->file_size);
                        file_control->group_id = __dir__.st_gid;
                        printf("%d\n", file_control->group_id);
                        file_control->user_id = __dir__.st_uid;
                        printf("%d\n", file_control->user_id);
                        char time_stamp[256];
                        file_control->time_create = __dir__.st_ctime;
                        strftime(time_stamp, sizeof(time_stamp), "%Y-%m-%d %H:%M:%S", localtime(&file_control->time_create));
                        printf("%s\n", time_stamp);
                    }
                }else{
                    perror("error");
                }
                exit(EXIT_SUCCESS);
            }
        }
    }else{
        perror("file aleady exists");
    }
    
    
    
   free(file_control); 
   free(file_extensions);
}
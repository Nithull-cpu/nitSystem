#include "library.c"
#include "file_sys.h"

extern file_sys create_function(char argv[]);
int main(int argc, char *argv[4]){
    if(argc == 3 || argc == 4){
        if(strcmp(argv[1], "-c") == 0){
            // call the create function
            create_function(argv[2]);
        }else if(strcmp(argv[1], "-d") == 0){
            // prompt the user for permenant delete query
            char prompt_user_input;
            // accept user input using the scanf and printf C function
            printf("Enter Y to delete or enter N to terminate process: ");
            scanf("%s", &prompt_user_input);

            if(prompt_user_input == 'Y'){
             // call the delete function
                delete_function(argv[2]);
            }else if(prompt_user_input == 'N'){
                perror("document not deleted");
            }else{
                perror("invalid user input");
            }
            
        }else if(strcmp(argv[1], "-df") == 0){
            // check if argc is less than 4 arguments
            if(argc == 4){
                // call the the directory and file create function
            }else{
                perror("Expecting 4 arguments passed in");
            }
        }else if(strcmp(argv[1], "-r") == 0){
            // check if argc is less than 4
            if(argc == 4){
                // call the rename function
                rename_function(argv[2], argv[3]);
            }else{
                perror("Expecting 4 arguments passed in");
            }
        }else if(strcmp(argv[1], "-sa") == 0){
            sort_ascending_function(argv[2]);
        }else if(strcmp(argv[1], "-o") == 0){
            // call the open function
        }else if(strcmp(argv[1], "-sd") == 0){
            // call the sort decending order
        }
    }else{
        perror("expecting 3 or 4 arguments");
    }
}
#include "library.c"

char find_file_type(char *argv[2]);

int main(int argc, char *argv[3]){
    if(argc == 3){
        if(strcmp(argv[1], "-ft") == 0){
            find_file_type(argv);
        }else{
            perror("expecting => '-ft'\nnone passed in!!");
            exit(EXIT_FAILURE);
        }
    }else{
        perror("less than 3 arguments passed in!!");
    }
    
}

char find_file_type(char *argv[2]){
    for(int i = 0; i < strlen(argv[2]); ++i){

        if((argv[2][i]) == (char) 46){
            printf("it's a valid file type!!");
            return *argv[2];
        }

    }
    perror("error");
}
#ifndef FILE_SYS_INFO
#define FILE_SYS_INFO
#include <unistd.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct file_sys
{
    char *file_name;
    char *file_type;
    int permit;
    time_t time_create;
    time_t time_modified;
    uint64_t file_size;
    uint8_t file_flag;
    uint16_t user_id;
    uint16_t group_id;
    int date_created;
    
}file_sys;


//FUNCTIONS DECLARTION!!
file_sys create_function(char argv[]);
file_sys delete_function( char argv[]);
file_sys sort_ascending_function(char argv[]);
file_sys rename_function(char argv[], char argv1[]);



#endif /* FILE_SYS_INFO*/

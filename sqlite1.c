#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1

typedef struct{
   char* buffer;
   size_t buffer_length;
   ssize_t input_length; 
} InputBuffer;

InputBuffer* new_input_buffer(){
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length=0;
    input_buffer->input_length=0;
    return input_buffer;    
}

void print_prompt() { printf("woosukdb > \n");}

void read_input(InputBuffer* inputBuffer){
     ssize_t bytes_read = getline(&(inputBuffer->buffer),&(inputBuffer->buffer_length),stdin);
     inputBuffer->input_length = bytes_read-1;
     inputBuffer->buffer[bytes_read-1] = 0;
}

void close_input_buffer(InputBuffer* input_buffer){
    free(input_buffer->buffer);
    free(input_buffer);
}

int main(int argc,char* argv[]){
    InputBuffer* inputBuffer = new_input_buffer();      
    while(true){    
        print_prompt();     
        read_input(inputBuffer);
        if(strcmp(inputBuffer->buffer,".exit")==0){
            close_input_buffer(inputBuffer); 
            exit(0);             
        }
        else{
            printf("'%s' is not valid command!\n",inputBuffer->buffer);      
        }
    }
}






#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct String{
    char* str;
    int length;
}String;

String* createString(char* str){
    String* createdStr = (String*)malloc(sizeof(String));
    createdStr->str = str;
    createdStr->length = strlen(str);
    return createdStr;
}

String *clearString(String* str){

}
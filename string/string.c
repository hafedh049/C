#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct String{
    char* str;
    int length;
}String;

const String* createString(const char* str){
    String* createdStr = (String*)malloc(sizeof(String));
    int len = strlen(str);
    createdStr->str = (char*)malloc(len*sizeof(char));
    createdStr->str = str;
    createdStr->length = strlen(str);
    return createdStr;
}

void clearString(const String* str){
    free(str->str);
    free(str);
}

int length(const String str){
    return str.length;
}

const String* capitalize(const String str){
    
}
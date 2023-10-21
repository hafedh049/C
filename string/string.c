#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct String
{
    char *str;
    int length;
} String;

const String *createString(const char *str)
{
    String *createdStr = (String *)malloc(sizeof(String));
    int len = strlen(str);
    createdStr->str = (char *)malloc((len + 1) * sizeof(char));
    strcpy(createdStr->str, str);
    createdStr->length = len;
    return createdStr;
}

void clearString(const String *str)
{
    if (str != NULL)
    {
        free(str->str);
        free(str);
    }
}

int length(const String str)
{
    return str.length;
}

const String *capitalize(const String *str)
{
    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc((str->length + 1) * sizeof(char));

    if (str->length > 0)
        result->str[0] = toupper(str->str[0]);

    for (int i = 1; i <= str->length; i++)
        result->str[i] = str->str[i];

    result->length = str->length;

    return result;
}
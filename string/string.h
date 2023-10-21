#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct String
{
    char *str;
    int length;
} String;

String *createString(char *);

void clearString(String *);

int length(String);

String *capitalize(String *);

String *casefold(String *);

String *center(String *, int, char);

int count(String *, String *);

bool endswith(String *, String *);

bool startswith(String *, String *);

int find(String *, String *);

int index(String *, String *);

bool isalnums(String *);

bool isalphas(String *);

bool isnumerics(String *);

bool islowers(String *);

bool isuppers(String *);

String *join(String *, String **, int);

String *lower(String *);

String *upper(String *);

String *ip(String *, char *);

String *replace(String *, String *, String *, int);

String **split(String *, char *, int *);

String *title(String *);

String *zfill(String *, int);

String *createSubstring(String *, int, int);

String **partition(String *, char);

String **rpartition(String *, char);

String *slice(String *, int, int);

char getCharAtIndex(String *, int);

String *swapcase(String *);

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

const String *createString(const char *);

void clearString(const String *);

int length(const String);

const String *capitalize(const String *);

const String *casefold(const String *);

const String *center(const String *, int, char);

int count(const String *, const String *);

bool endswith(const String *, const String *);

bool startswith(const String *, const String *);

int find(const String *, const String *);

int index(const String *, const String *);

bool isalnums(const String *);

bool isalphas(const String *);

bool isnumerics(const String *);

bool islowers(const String *);

bool isuppers(const String *);

const String *join(const String *, const String **, int);

const String *lower(const String *);

const String *upper(const String *);

const String *ip(const String *, const char *);

const String *replace(const String *, const String *, const String *, int);

String **split(const String *, char, int *);

String *title(const String *);

String *zfill(const String *, int);

String *createSubstring(const String *, int, int);

String **partition(const String *, char);

String **rpartition(const String *, char);

String *slice(const String *, int, int);

char getCharAtIndex(const String *, int);

String *swapcase(const String *);

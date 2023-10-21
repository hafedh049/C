#include "string/string.h"

int main() {
    // Test createString
    const char* originalStr = "Hello, World!";
    const String* str = createString(originalStr);

    printf("Original String: %s\n", originalStr);
    printf("Created String: %s\n", str->str);
    printf("String Length: %d\n", str->length);

    // Test split
    int numSplits;
    char separator = ',';
    char** splits = split(str, separator, &numSplits);

    printf("\nSplit String (separator: ','):\n");
    for (int i = 0; i < numSplits; i++) {
        printf("Split %d: %s\n", i, splits[i]);
        free(splits[i]); // Free allocated memory
    }
    free(splits); // Free the splits array

    // Test strip
    char chars[] = " !";
    String* stripped = strip(str, chars);

    printf("\nStripped String (removed leading and trailing ' !'):\n%s\n", stripped->str);
    free(stripped);

    // Test title
    String* titleStr = title(str);

    printf("\nTitle-cased String:\n%s\n", titleStr->str);
    free(titleStr);

    // Test swapcase
    String* swapped = swapcase(str);

    printf("\nSwapped Case String:\n%s\n", swapped->str);
    free(swapped);

    // Free the original String
    freeString(str);

    return 0;
}

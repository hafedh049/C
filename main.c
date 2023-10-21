#include "string/string.c"

int main() {
    // Test createString
    char* originalStr = "Hello, World!";
    String* str = createString(originalStr);

    printf("Original String: %s\n", originalStr);
    printf("Created String: %s\n", str->str);
    printf("String Length: %d\n", str->length);

    return 0;
}

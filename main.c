#include "string/string.c"

int main() {
    char* originalStr = "Hello, World!";
    String* str = createString(originalStr);

    printf("Original String: %s\n", originalStr);
    printf("Created String: %s\n", str->str);
    printf("String Length: %d\n", str->length);
    char* words[] = { "Hello", "World", "OpenAI", "GPT-3" };
    int numWords = sizeof(words) / sizeof(words[0]);

    String** strings = (String**)malloc(numWords * sizeof(String*));
    for (int i = 0; i < numWords; i++) {
        strings[i] = createString(words[i]);
    }
    printf("%s\n", join(createString("||"),strings,numWords)->str);
    return 0;
}

#include "string.h"

String *createString(char *str)
{
    String *createdStr = (String *)malloc(sizeof(String));
    int len = strlen(str);
    createdStr->str = (char *)malloc((len + 1) * sizeof(char));
    strcpy(createdStr->str, str);
    createdStr->length = len;
    return createdStr;
}

void clearString(String *str)
{
    if (str != NULL)
    {
        free(str->str);
        free(str);
    }
}

int length(String str)
{
    return str.length;
}

String *capitalize(String *str)
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

String *casefold(String *str)
{
    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc((str->length + 1) * sizeof(char));

    for (int i = 0; i <= str->length; i++)
        result->str[i] = tolower(str->str[i]);

    result->length = str->length;

    return result;
}

String *center(String *str, int width, char fillchar)
{
    if (width <= str->length)
        return str;

    const int padding = width - str->length;
    const int left_padding = padding / 2;
    const int right_padding = padding - left_padding;

    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc((width + 1) * sizeof(char));

    for (int i = 0; i < left_padding; i++)
        result->str[i] = fillchar;

    for (int i = 0; i < str->length; i++)
        result->str[left_padding + i] = str->str[i];

    for (int i = 0; i < right_padding; i++)
        result->str[left_padding + str->length + i] = fillchar;

    result->str[width] = '\0';
    result->length = width;

    return result;
}

int count(String *str, String *substring)
{
    int count = 0;
    char *position = str->str;
    while ((position = strstr(position, substring->str)) != NULL)
    {
        count++;
        position += substring->length;
    }
    return count;
}

bool endswith(String *str, String *suffix)
{
    int str_len = str->length;
    int suffix_len = suffix->length;

    if (str_len < suffix_len)
        return false;

    const char *str_end = str->str + str_len - suffix_len;
    return strcmp(str_end, suffix->str) == 0;
}

bool startswith(String *str, String *prefix)
{
    if (str->length < prefix->length)
        return false;

    return strncmp(str->str, prefix->str, prefix->length) == 0;
}

int find(String *str, String *substring)
{
    const char *position = strstr(str->str, substring->str);
    if (position == NULL)
        return -1;
    return position - str->str;
}

int index(String *str, String *substring)
{
    int position = find(str, substring);
    if (position == -1)
    {
        printf("Substring not found\n");
        exit(1);
    }
    return position;
}

bool isalnums(String *str)
{
    for (int i = 0; i < str->length; i++)
        if (!isalnum(str->str[i]))
            return false;
    return true;
}

bool isalphas(String *str)
{
    for (int i = 0; i < str->length; i++)
        if (!isalpha(str->str[i]))
            return false;
    return true;
}

bool isnumerics(String *str)
{
    for (int i = 0; i < str->length; i++)
        if (!isdigit(str->str[i]))
            return false;
    return true;
}

bool islowers(String *str)
{
    for (int i = 0; i < str->length; i++)
        if (!islower(str->str[i]))
            return false;
    return true;
}

bool isuppers(String *str)
{
    for (int i = 0; i < str->length; i++)
        if (!isupper(str->str[i]))
            return false;
    return true;
}

String *join(String *separator, String **strings, int num_strings)
{
    int total_length = 0;
    for (int i = 0; i < num_strings; i++)
        total_length += strings[i]->length;

    total_length += (num_strings - 1) * separator->length;

    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc((total_length + 1) * sizeof(char));

    char *result_position = result->str;

    for (int i = 0; i < num_strings; i++)
    {
        const int str_length = strings[i]->length;
        memcpy(result_position, strings[i]->str, str_length);
        result_position += str_length;

        if (i < num_strings - 1)
        {
            memcpy(result_position, separator->str, separator->length);
            result_position += separator->length;
        }
    }

    result->str[total_length] = '\0';
    result->length = total_length;

    return result;
}

String *lower(String *str)
{
    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc((str->length + 1) * sizeof(char));

    for (int i = 0; i < str->length; i++)
    {
        result->str[i] = tolower(str->str[i]);
    }

    result->str[str->length] = '\0';
    result->length = str->length;

    return result;
}

String *upper(String *str)
{
    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc((str->length + 1) * sizeof(char));

    for (int i = 0; i < str->length; i++)
    {
        result->str[i] = toupper(str->str[i]);
    }

    result->str[str->length] = '\0';
    result->length = str->length;

    return result;
}

String *strip(String *str, const char *chars)
{
    int left = 0;
    int right = str->length - 1;

    while (left <= right && strchr(chars, str->str[left]))
        left++;

    while (right >= left && strchr(chars, str->str[right]))
        right--;

    const int new_length = right - left + 1;

    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc((new_length + 1) * sizeof(char));
    memcpy(result->str, str->str + left, new_length);
    result->str[new_length] = '\0';
    result->length = new_length;

    return result;
}

String *replace(String *str, String *old, String *new_str, int count)
{
    if (count <= 0)
        return str;

    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc((str->length + 1) * sizeof(char));

    const char *input_str = str->str;
    char *output_str = result->str;

    while (count > 0)
    {
        const char *found = strstr(input_str, old->str);
        if (found == NULL)
            break;

        int before_length = found - input_str;
        memcpy(output_str, input_str, before_length);
        output_str += before_length;
        input_str = found + old->length;

        memcpy(output_str, new_str->str, new_str->length);
        output_str += new_str->length;
        count--;
    }

    int remaining_length = str->length - (input_str - str->str);
    memcpy(output_str, input_str, remaining_length);
    output_str += remaining_length;

    *output_str = '\0';

    result->length = output_str - result->str;
    return result;
}

String **split(String *str, char *separator, int *numSplits)
{
    *numSplits = 0;
    String **splits = NULL;
    char *token = strtok(str->str, separator);

    while (token != NULL)
    {
        (*numSplits)++;
        splits = (String **)realloc(splits, sizeof(String *) * (*numSplits));
        splits[(*numSplits) - 1] = createString(token);
        token = strtok(NULL, separator);
    }

    return splits;
}

String *title(String *str)
{
    int length = str->length;
    char *titleStr = (char *)malloc((length + 1) * sizeof(char));

    int capitalizeNext = 1;
    for (int i = 0; i < length; i++)
    {
        char c = str->str[i];
        if (isalpha(c))
        {
            if (capitalizeNext)
            {
                titleStr[i] = toupper(c);
                capitalizeNext = 0;
            }
            else
                titleStr[i] = tolower(c);
        }
        else
        {
            titleStr[i] = c;
            capitalizeNext = 1;
        }
    }

    titleStr[length] = '\0';

    return createString(titleStr);
}

String *zfill(String *str, int width)
{
    if (width <= str->length)
        return createString(str->str);

    int numZeros = width - str->length;
    char *zfilledStr = (char *)malloc((width + 1) * sizeof(char));
    memset(zfilledStr, '0', numZeros);
    strcpy(zfilledStr + numZeros, str->str);
    zfilledStr[width] = '\0';

    return createString(zfilledStr);
}

String *createSubstring(String *str, int start, int end)
{
    if (start < 0)
        start = 0;

    if (end > str->length)
        end = str->length;

    if (start >= end)
        return createString("");

    int length = end - start;
    char *substring = (char *)malloc((length + 1) * sizeof(char));

    for (int i = start; i < end; i++)
        substring[i - start] = str->str[i];

    substring[length] = '\0';

    return createString(substring);
}

String **partition(String *str, char separator)
{
    int separatorIndex = -1;
    for (int i = 0; i < str->length; i++)
        if (str->str[i] == separator)
        {
            separatorIndex = i;
            break;
        }

    String **parts = (String **)malloc(3 * sizeof(String *));

    if (separatorIndex >= 0)
    {
        parts[0] = createSubstring(str, 0, separatorIndex);
        parts[1] = createSubstring(str, separatorIndex, separatorIndex + 1);
        parts[2] = createSubstring(str, separatorIndex + 1, str->length);
    }
    else
    {
        parts[0] = createString(str->str);
        parts[1] = createString("");
        parts[2] = createString("");
    }

    return parts;
}

String **rpartition(String *str, char separator)
{
    int separatorIndex = -1;
    for (int i = str->length - 1; i >= 0; i--)
        if (str->str[i] == separator)
        {
            separatorIndex = i;
            break;
        }

    String **parts = (String **)malloc(3 * sizeof(String *));

    if (separatorIndex >= 0)
    {
        parts[0] = createSubstring(str, 0, separatorIndex);
        parts[1] = createSubstring(str, separatorIndex, separatorIndex + 1);
        parts[2] = createSubstring(str, separatorIndex + 1, str->length);
    }
    else
    {
        parts[0] = createString("");
        parts[1] = createString("");
        parts[2] = createString(str->str);
    }

    return parts;
}

String *slice(String *str, int start, int end)
{
    if (start < 0 || start >= str->length || end < start || end >= str->length)
        return createString("");

    char *slicedStr = (char *)malloc((end - start + 1) * sizeof(char));
    for (int i = start, j = 0; i <= end; i++, j++)
        slicedStr[j] = str->str[i];
    slicedStr[end - start + 1] = '\0';

    String *result = createString(slicedStr);
    free(slicedStr);
    return result;
}

char getCharAtIndex(String *str, int index)
{
    if (index < 0 || index >= str->length)
        return '\0';
    return str->str[index];
}

String *swapcase(String *str)
{
    char *swappedStr = (char *)malloc((str->length + 1) * sizeof(char));

    for (int i = 0; i < str->length; i++)
    {
        char c = str->str[i];
        if (c >= 'a' && c <= 'z')
            swappedStr[i] = c - 'a' + 'A';
        else if (c >= 'A' && c <= 'Z')
            swappedStr[i] = c - 'A' + 'a';
        else
            swappedStr[i] = c;
    }
    swappedStr[str->length] = '\0';

    String *result = createString(swappedStr);
    free(swappedStr);
    return result;
}

char *toString(const String str)
{
    int resultLength = str.length + 2;
    char *result = (char *)malloc(resultLength + 1);
    snprintf(result, resultLength + 1, "\"%s\"", str.str);
    return result;
}
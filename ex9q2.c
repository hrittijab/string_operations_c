#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//https://www.geeksforgeeks.org/string-functions-in-c/
void concatenate(char *num1, char *num2)
{
    char *resultString;
    int num1Len = strlen(num1);
    int num2Len = strlen(num2);
    resultString = (char *)malloc((num1Len + num2Len + 1) * sizeof(char *));
    for (int i = 0; i < num1Len; i++)
    {
        resultString[i] = num1[i];
    }
    for (int j = 0; j < num2Len; j++)
    {
        resultString[num1Len + j] = num2[j];
    }
    resultString[num1Len + num2Len] = '\0';
    printf("%s\n", resultString);
    free(resultString);
    return;
}

void addNumbers(char *num1, char *num2)
{
    int num1Len = strlen(num1);
    int num2Len = strlen(num2);
    int maxLen;
    int carry = 0;
    if (num1Len > num2Len)
    {
        maxLen = num1Len;
    }
    else
    {
        maxLen = num2Len;
    }
    char *finalString;
    finalString = (char *)malloc((maxLen + 1) * sizeof(char *));
    int i, sum;
    i = maxLen;
    int num1Index = 0;
    int num2Index = 0;
    while (i > 0)
    {
        int digit1 = 0;
        int digit2 = 0;

        if (num1Index < num1Len)
        {
            digit1 = num1[num1Len - 1 - num1Index] - '0';
            num1Index++;
        }

        if (num2Index < num2Len)
        {
            digit2 = num2[num2Len - 1 - num2Index] - '0';
            num2Index++;
        }

        sum = digit1 + digit2 + carry;
        carry = sum / 10;

        finalString[i] = (sum % 10) + '0';

        i--;
    }
    if (carry == 1)
    {
        finalString[0] = carry + '0';
        finalString[maxLen + 1] = '\0';

        printf("%s\n", finalString);
    }
    else
    {
        finalString[maxLen + 1] = '\0';
        printf("%s\n", finalString + 1);
    }
    free(finalString);
    return;
}

void rotate(char *num, int rotations)
{
    int len = strlen(num);
    char *result = (char *)malloc((len + 1) * sizeof(char));
    char *string = (char *)malloc((len + 1) * sizeof(char));
    rotations = rotations % len;
    strncpy(result, num + rotations, len - rotations);
    result[len - rotations] = '\0';
    strncat(result, num, rotations);
    if (strlen(result) == 1 && result[0] == '0')
    {
        string[0] = '0';
        string[1] = '\0';
    }
    else
    {
        int k = 0;
        for (k = 0; k < len; k++)
        {
            if (result[k] != '0')
            {
                break;
            }
        }

        int v = 0;
        for (int m = k; m < len; m++)
        {
            string[v] = result[m];
            v++;
        }
        string[len - k] = '\0';
    }
    printf("%s\n", string);
    free(result);
    free(string);

    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i = 0;
    int num;

    while (i < n)
    {

        char *operate = (char *)malloc((4) * sizeof(char));
        char *num1 = (char *)malloc((101) * sizeof(char));
        char *num2 = (char *)malloc((101) * sizeof(char));
        scanf("%s %s %s", num1, operate, num2);
        getchar();
        if (operate[0] == '+')
        {
            addNumbers(num1, num2);
            i++;
        }
        else if (operate[0] == '@')
        {
            concatenate(num1, num2);
            i++;
        }
        else if (operate[0] == 'r')
        {
            num = atoi(num2);
            rotate(num1, num);
            i++;
        }
        free(operate);
        free(num1);
        free(num2);
    }
}

#include <stdio.h>

#define max_size 20

int main()
{
    printf("Hello World\n");
    char str[max_size];
    
    printf("Enter string : ");
    fgets(str, max_size, stdin);
    printf("String entered : %s\n", str);
    
    
    return 0;
}

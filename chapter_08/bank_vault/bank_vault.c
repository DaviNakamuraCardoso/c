#include <stdio.h>
#include <checksum.h>
#include <encrypt.h>

int main(void)
{
    char s[] = "Speak friend and enter";
    encrypt(s);

    printf("Encrypted to %s\n", s);
    printf("Checksum is %i\n", checksum(s));

    encrypt(s);

    printf("Decripted to %s\n", s);
    printf("Checkum is %i\n", checksum(s));

    return 0; 
}

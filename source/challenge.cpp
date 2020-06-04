#include <windows.h>
#include <stdio.h>

#define TRIAL "Trial..."
#define PERSONAL "Personal..."
#define PROFESSIONAL "Professional..."
#define ENTERPRISE "Enterprise..."
#define SKILLED "Skilled..."
#define BAD "Invalid..."


int main(int argc, char *argv[]) {
    char Msg[20] = BAD;

    printf("[ReverseMe Challenge]\n[by YANiS]\n\nYour Registration Details: ");


    if (argc > 1) {
        DWORD len = 0 ;

        if (CryptStringToBinaryA(argv[1],
                                 strlen(argv[1]),
                                 CRYPT_STRING_BASE64 | CRYPT_STRING_BASE64HEADER,
                                 NULL,
                                 &len,
                                 NULL,
                                 NULL)) {

            if (len < 5) {
                strcpy(Msg, BAD);
            }

            if ((len > 12) & (len < 21))
                strcpy(Msg, PERSONAL);

            if ((len > 64) & (len < 66))
                strcpy(Msg, SKILLED);

            if ((len > 29) & (len < 31))
                strcpy(Msg, ENTERPRISE);

            if ((len > 6) & (len < 10))
                strcpy(Msg, TRIAL);

            if ((len > 32) & (len < 42))
                strcpy(Msg, PROFESSIONAL);
        } else
            strcpy(Msg, BAD);
    }
    printf("%s\n", Msg);
    getchar();
    return 0;

}
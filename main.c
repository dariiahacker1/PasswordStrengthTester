#include "functions.h"

int main() {

    title();

    char password[MAX_PASSWORD_LENGTH];
    printf("ENTER THE PASSWORD: ");

    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;

    struct info pswd_info = {0};

    standard_test(password);
    length_checker(password, &pswd_info);
    similarity_to_popular_passwords(password, &pswd_info);

    conclusion(&pswd_info);
    return 0;
}

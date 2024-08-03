#include "functions.h"

void standard_test(const char *password) {

    bool normal_length = strlen(password) >= 8;
    bool has_digit = false;
    bool has_lower = false;
    bool has_upper = false;
    bool has_special = false;

    while (*password) {

        if (isdigit(*password)) {
            has_digit = true;
        } else if (islower(*password)) {
            has_lower = true;
        } else if (isupper(*password)) {
            has_upper = true;
        } else if (ispunct(*password) || isspace(*password)) {
            has_special = true;
        }

        password++;
    }

    if (!normal_length || !has_digit || !has_lower || !has_upper || !has_special) {
        printf("\nPAY ATTENTION!\n");

        if (!normal_length) printf("Your password must contain at least 8 characters\n");
        if (!has_digit) printf("Your password must contain at least 1 number \n");
        if (!has_special) printf("Your password must contain at least 1 special character \n");
        if (!has_lower || !has_upper) printf("Your password must contain both lowercase and uppercase letters\n");
    }
}


void length_checker(const char *password, struct info *pswd_info) {

    size_t length_of_password = strlen(password);
    pswd_info->length = length_of_password;

    //Numbers(10 different: 0-9), Letters(52 different: A-Z and a-z), Special characters (32 different)
    int possible_number_of_characters = 94;
    double possible_combinations = pow(possible_number_of_characters, (double) length_of_password);

    double number_of_passwords_to_check = 0;

    for(int i = 1; i <= length_of_password; i++){
        number_of_passwords_to_check +=  pow(possible_number_of_characters, i);
    }

    //500000 - average number of passwords that an attacker can test per second
    double time_required_to_decrypt = number_of_passwords_to_check / 500000.0;
    double time = time_required_to_decrypt;
    char time_name[30] = "seconds";

    if (time_required_to_decrypt >= 31536000.0) {
        time = time_required_to_decrypt / 31536000.0;
        strcpy(time_name, "years");
    } else if (time_required_to_decrypt >= 86400.0) {
        time = time_required_to_decrypt / 86400.0;
        strcpy(time_name, "days");
    } else if (time_required_to_decrypt >= 3600.0) {
        time = time_required_to_decrypt / 3600.0;
        strcpy(time_name, "hours");
    } else if (time_required_to_decrypt >= 60.0) {
        time = time_required_to_decrypt / 60.0;
        strcpy(time_name, "minutes");
    }

    printf("\nPOSSIBLE PASSWORD COMBINATIONS %zu CHARACTERS LONG: %.0f\n", length_of_password, possible_combinations);
    printf("NUMBER OF PASSWORDS THAT NEED TO BE CHECKED TO CRACK: %.0f\n", number_of_passwords_to_check);
    printf("TIME REQUIRED TO DECRYPT: %.2f %s\n", time, time_name);

}

void similarity_to_popular_passwords(const char *password, struct info *pswd_info) {

    FILE *file = fopen("resources/rockyou.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {

        line[strcspn(line, "\n")] = 0;

        if (strcmp(password, line) == 0) {
            pswd_info->similarity = 1;
            break;
        }

    }

    fclose(file);

}

void conclusion(struct info *pswd_info) {

    printf("\nREVIEW:\n");
    printf("#  ");
    if (pswd_info->length >= 20) {
        printf("Your password is very strong. Excellent length and complexity!\n");
    } else if (pswd_info->length >= 14) {
        printf("Your password is strong. Good length and complexity.\n");
    } else if (pswd_info->length >= 8) {
        printf("Your password is moderate. Consider increasing its length and complexity for better security.\n");
    } else {
        printf("Your password is very weak. It is highly recommended to choose a longer and more complex password.\n");
    }

    printf("#  ");
    switch (pswd_info->similarity) {
        case 1:
            printf("WARNING: Your password is found in a list of commonly used passwords. Consider using a more unique password to enhance security.\n");
            break;
        default:
            printf("Your password was not found in the list of frequently used passwords. Keep up the good work!\n");
            break;
    }

    printf("\nGENERAL ADVICE:\n");
    printf("1. Use a mix of uppercase and lowercase letters, numbers, and special characters.\n");
    printf("2. Avoid using easily guessable information like common words or personal details.\n");
    printf("3. Consider using a password manager to generate and store complex passwords.\n");

}


void title() {

    printf("    ___                                    _   _____          _            \n");
    printf("   / _ \\__ _ ___ _____      _____  _ __ __| | /__   \\___  ___| |_ ___ _ __ \n");
    printf("  / /_)/ _` / __/ __\\ \\ /\\ / / _ \\| '__/ _` |   / /\\/ _ \\/ __| __/ _ \\ '__|\n");
    printf(" / ___/ (_| \\__ \\__ \\\\ V  V / (_) | | | (_| |  / / |  __/\\__ \\ ||  __/ |   \n");
    printf(" \\/    \\__,_|___/___/ \\_/\\_/ \\___/|_|  \\__,_|  \\/   \\___||___/\\__\\___|_|   \n\n");

}

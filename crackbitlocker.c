#include <string.h>
#include <stdio.h>

#define MAX_PASS_LENGTH 18
#define CHAR_SET_SIZE 36

const char char_set[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                            'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                            'u', 'v', 'w', 'x', 'y', 'z',
                            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                            'U', 'V', 'W', 'X', 'Y', 'Z'};

char * get_disk_password(char *disk) {
    char *password;

    // Allouer de la mémoire pour le mot de passe
    password = malloc(MAX_PASS_LENGTH + 1);

    // Obtenir le mot de passe du disque
    if(disk_get_password(disk, password, MAX_PASS_LENGTH + 1) != 0) {
        // Libérer la mémoire allouée si l'obtention du mot de passe échoue
        free(password);
        return NULL;
    }

    // Retourner le mot de passe
    return password;
}

int unlock_disk_with_password(char *disk, char *pass) {
    char *disk_password;
    int is_unlocked;

    // Obtenir le mot de passe du disque
    disk_password = get_disk_password(disk);

    // Comparer le mot de passe du disque avec le mot de passe fourni
    is_unlocked = strcmp(disk_password, pass) == 0;

    // Libérer le mot de passe du disque
    free(disk_password);

    // Retourner le résultat
    return is_unlocked;
}

int main(int argc, char **argv)
{
    char pass[MAX_PASS_LENGTH + 1];
    int i;
    char *disk;

    if(argc < 2) {
        fprintf(stderr, "Veuillez spécifier un disque\n");
        return 1;
    }

    disk = argv[1];

    /* Générer toutes les combinaisons possibles de mots de passe en commencer par 4 caractères*/
    for(i = 0; i < CHAR_SET_SIZE; i++) {
    pass[0] = char_set[i];
    pass[1] = char_set[i];
    pass[2] = char_set[i];
    pass[3] = char_set[i];
    pass[4] = '\0';

        while(strlen(pass) <= MAX_PASS_LENGTH) {
            /* Tenter de déverrouiller le disque avec le mot de passe actuel en specifiant le disk */
            if(unlock_disk_with_password(disk, pass)) {
                printf("Le mot de passe est : %s\n", pass);
                return 0;
            }

            strcat(pass, char_set[i]);
        }
    }

    printf("Aucun mot de passe trouvé\n");
    return 1;
}

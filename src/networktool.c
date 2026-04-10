#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LOG_ENTRIES 100
#define MAX_ENTRY_LEN 100

void mostrar_menu() {
    printf("\n===NÄTVERKSVERKTYG===\n");
    printf("1. Validera IP-adress\n");
    printf("2. Validera port\n");
    printf("3. Visa logg\n");
    printf("4. Avsluta\n");
}

bool validar_ip(const char *ip) {
    int a, b, c, d;
    char extra;

    if (sscanf(ip, "%d.%d.%d.%d%c", &a, &b, &c, &d, &extra) != 4) {
        return false;
    }

    if (a < 0 || a > 255) return false;
    if (b < 0 || b > 255) return false;
    if (c < 0 || c > 255) return false;
    if (d < 0 || d > 255) return false;

    return true;
}

bool validar_port(const char *port_str) {
    char *endptr;
    long port = strtol(port_str, &endptr, 10);

    if (port_str == endptr) {
        return false;
    }

    while (*endptr == ' ' || *endptr == '\n' || *endptr == '\t') {
        endptr++;
    }

    if (*endptr != '\0') {
        return false;
    }

    return port >= 1 && port <= 65535;
}

void mostrar_log(char log[][MAX_ENTRY_LEN], int log_count) {
    printf("\nLOGG\n");
    for (int i = 0; i < log_count; i++) {
        printf("%d. %s\n", i + 1, log[i]);
    }
}

int main() {
    char log[MAX_LOG_ENTRIES][MAX_ENTRY_LEN];
    int log_count = 0;

    char buffer[256];
    int choice;

    while (1) {
        mostrar_menu();
        printf("Välj ett alternativ: ");

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            continue;
        }

        choice = atoi(buffer);

        if (choice == 1) {
            char ip[256];
            printf("Ange IP-adress: ");
            if (!fgets(ip, sizeof(ip), stdin)) continue;
            ip[strcspn(ip, "\n")] = '\0';

            if (validar_ip(ip)) {
                printf("%s är en giltig IP-adress.\n", ip);
                snprintf(log[log_count++], MAX_ENTRY_LEN, "IP %s - giltig", ip);
            } else {
                printf("%s är inte en giltig IP-adress.\n", ip);
                snprintf(log[log_count++], MAX_ENTRY_LEN, "IP %s - ogiltig", ip);
            }

        } else if (choice == 2) {
            char port_str[256];
            printf("Ange port: ");
            if (!fgets(port_str, sizeof(port_str), stdin)) continue;
            port_str[strcspn(port_str, "\n")] = '\0';

            if (validar_port(port_str)) {
                printf("%s är en giltig port.\n", port_str);
                snprintf(log[log_count++], MAX_ENTRY_LEN, "Port %s - giltig", port_str);
            } else {
                printf("%s är inte en giltig port.\n", port_str);
                snprintf(log[log_count++], MAX_ENTRY_LEN, "Port %s - ogiltig", port_str);
            }

        } else if (choice == 3) {
            mostrar_log(log, log_count);

        } else if (choice == 4) {
            printf("Totalt antal valideringar: %d\n", log_count);
            printf("Avslutar.\n");
            break;

        } else {
            printf("Ogiltigt val.\n");
        }
    }

    return 0;
}
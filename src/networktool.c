//Bibliotek

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Konstanter

#define MAX_LOG_ENTRIES 100
#define MAX_ENTRY_LEN 300

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

//Menyfunktion

void mostrar_menu() {
    printf(BLUE"\n===NÄTVERKSVERKTYG===\n" RESET);
    printf(BLUE"1. Validera IP-adress\n" RESET);
    printf(BLUE"2. Validera port\n" RESET);
    printf(BLUE"3. Visa logg\n" RESET);
    printf(BLUE"4. Avsluta\n" RESET);
}

//Valideringsfunktioner

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

//Loggfunktion

void mostrar_log(char log[][MAX_ENTRY_LEN], int log_count) {
    printf(GREEN"\nLOGG\n" RESET);
    for (int i = 0; i < log_count; i++) {
        printf(GREEN"%d. %s\n" RESET, i + 1, log[i]);
    }
}

//Huvudfunktion

int main() {
    char log[MAX_LOG_ENTRIES][MAX_ENTRY_LEN];
    int log_count = 0;

    char buffer[256];
    int choice;

    while (1) {
        mostrar_menu();
        printf(YELLOW"Välj ett alternativ: " RESET);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            continue;
        }

        choice = atoi(buffer);

        if (choice == 1) {
            char ip[256];
            printf(YELLOW"Ange IP-adress: " RESET);
            if (!fgets(ip, sizeof(ip), stdin)) continue;
            ip[strcspn(ip, "\n")] = '\0';

            if (validar_ip(ip)) {
                printf(GREEN"%s är en giltig IP-adress.\n", ip);
                snprintf(log[log_count++], MAX_ENTRY_LEN, "IP %s - giltig", ip);
            } else {
                printf(RED"%s är inte en giltig IP-adress.\n", ip);
                snprintf(log[log_count++], MAX_ENTRY_LEN, "IP %s - ogiltig", ip);
            }

        } else if (choice == 2) {
            char port_str[256];
            printf(YELLOW"Ange port: " RESET);
            if (!fgets(port_str, sizeof(port_str), stdin)) continue;
            port_str[strcspn(port_str, "\n")] = '\0';

            if (validar_port(port_str)) {
                printf(GREEN"%s är en giltig port.\n", port_str);
                snprintf(log[log_count++], MAX_ENTRY_LEN, "Port %s - giltig", port_str);
            } else {
                printf(RED"%s är inte en giltig port.\n", port_str);
                snprintf(log[log_count++], MAX_ENTRY_LEN, "Port %s - ogiltig", port_str);
            }

        } else if (choice == 3) {
            mostrar_log(log, log_count);

        } else if (choice == 4) {
            printf(YELLOW"Totalt antal valideringar: %d\n" RESET, log_count);
            printf(YELLOW"Avslutar.\n" RESET);
            break;

        } else {
            printf(RED"Ogiltigt val.\n" RESET);
        }
    }

    return 0;
}
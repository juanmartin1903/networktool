import re

BLUE_BG = "\033[44m"
WHITE_TX = "\033[97m"
YELLOW = "\033[33m"
GREEN = "\033[32m"
RED = "\033[31m"
RESET = "\033[0m"

log = []

def show_menu():
    print(BLUE_BG + WHITE_TX + "\n+------------------------+" + RESET)
    print(BLUE_BG + WHITE_TX + "|    NÄTVERKSVERKTYG     |" + RESET)
    print(BLUE_BG + WHITE_TX + "+------------------------+" + RESET)

    print(WHITE_TX + "1. Validera IP-adress" + RESET)
    print(WHITE_TX + "2. Validera port" + RESET)
    print(WHITE_TX + "3. Visa logg" + RESET)
    print(WHITE_TX + "4. Avsluta" + RESET)

def validate_ip(ip):
    pattern = r"^(\d{1,3}\.){3}\d{1,3}$"
    if not re.match(pattern, ip):
        return False
    parts = ip.split(".")
    return all(0 <= int(p) <= 255 for p in parts)

def validate_port(port):
    if not port.isdigit():
        return False
    port = int(port)
    return 1 <= port <= 65535

# Rensa terminalen och sätt bakgrundsfärg

print("\033[2J\033[H")
print("\033[44m")

while True:
    show_menu()
    choice = input(YELLOW + "Välj ett alternativ: " + RESET)

    if choice == "1":
        ip = input(YELLOW + "Ange IP-adress: " + RESET)
        if validate_ip(ip):
            print(GREEN + f"{ip} är en giltig IP-adress." + RESET)
            log.append(f"IP {ip} - giltig")
        else:
            print(RED + f"{ip} är inte en giltig IP-adress." + RESET)
            log.append(f"IP {ip} - ogiltig")

    elif choice == "2":
        port = input(YELLOW + "Ange port: " + RESET)
        if validate_port(port):
            print(GREEN + f"{port} är en giltig port." + RESET)
            log.append(f"Port {port} - giltig")
        else:
            print(RED + f"{port} är inte en giltig port." + RESET)
            log.append(f"Port {port} - ogiltig")

    elif choice == "3":
        print(GREEN + "\nLOGG" + RESET)
        for i, entry in enumerate(log, 1):
            print(GREEN + f"{i}. {entry}" + RESET)

    elif choice == "4":
        print(YELLOW + f"Totalt antal valideringar: {len(log)}" + RESET)
        print(YELLOW + "Avslutar." + RESET)
        break

    else:
        print(RED + "Ogiltigt val." + RESET)

 # återställ terminalfärger
 
    print(RESET) 
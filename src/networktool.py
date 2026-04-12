## Färgkoder för terminalen
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
RESET = "\033[0m"


## Nätverksverktyg - Meny
def show_menu():
    print(f"\n==={BLUE}NÄTVERKSVERKTYG{RESET}===")
    print(f"{BLUE}1. Validera IP-adress{RESET}")
    print(f"{BLUE}2. Validera port{RESET}")
    print(f"{BLUE}3. Visa logg{RESET}")
    print(f"{BLUE}4. Avsluta{RESET}")

## Valideringsfunktioner för IP-adress

def validate_ip(ip: str) -> bool:
    parts = ip.strip().split(".")
    if len(parts) != 4:
        return False
    for part in parts:
        if not part.isdigit():
            return False
        value = int(part)
        if value < 0 or value > 255:
            return False
    return True

## Valideringsfunktion för portnummer

def validate_port(port_str: str) -> bool:
    port_str = port_str.strip()
    if not port_str.isdigit():
        return False
    port = int(port_str)
    return 1 <= port <= 65535

## Loggfunktion

def show_log(log):
    print(f"\n{GREEN}LOGG{RESET}")
    for i, entry in enumerate(log, start=1):
        print(f"{GREEN}{i}. {entry}{RESET}")

## Huvudfunktion

def main():
    log = []

    while True:
        show_menu()
        choice = input(f"{YELLOW}Välj ett alternativ: {RESET}").strip()

        if choice == "1":
            ip = input(f"{YELLOW}Ange IP-adress: {RESET}").strip()
            if validate_ip(ip):
                print(f"{GREEN}{ip} är en giltig IP-adress.{RESET}")
                log.append(f"IP {ip} - giltig")
            else:
                print(f"{RED}{ip} är inte en giltig IP-adress.{RESET}")
                log.append(f"IP {ip} - ogiltig")

        elif choice == "2":
            port_str = input(f"{YELLOW}Ange port: {RESET}").strip()
            if validate_port(port_str):
                print(f"{GREEN}{port_str} är en giltig port.{RESET}")
                log.append(f"Port {port_str} - giltig")
            else:
                print(f"{RED}{port_str} är inte en giltig port.{RESET}")
                log.append(f"Port {port_str} - ogiltig")

        elif choice == "3":
            show_log(log)

        elif choice == "4":
            print(f"{GREEN}Totalt antal valideringar: {len(log)}{RESET}")
            print(f"{GREEN}Avslutar.{RESET}")
            break

        else:
            print(f"{RED}Ogiltigt val.{RESET}")

## Kör programmet

if __name__ == "__main__":
        main()
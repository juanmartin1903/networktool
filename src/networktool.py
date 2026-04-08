## Nätverksverktyg - Meny
def show_menu():
    print("\n===NÄTVERKSVERKTYG===")
    print("1. Validera IP-adress")
    print("2. Validera port")
    print("3. Visa logg")
    print("4. Avsluta")

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
    print("\nLOGG")
    for i, entry in enumerate(log, start=1):
        print(f"{i}. {entry}")

## Huvudfunktion

def main():
    log = []

    while True:
        show_menu()
        choice = input("Välj ett alternativ: ").strip()

        if choice == "1":
            ip = input("Ange IP-adress: ").strip()
            if validate_ip(ip):
                print(f"{ip} är en giltig IP-adress.")
                log.append(f"IP {ip} - giltig")
            else:
                print(f"{ip} är inte en giltig IP-adress.")
                log.append(f"IP {ip} - ogiltig")

        elif choice == "2":
            port_str = input("Ange port: ").strip()
            if validate_port(port_str):
                print(f"{port_str} är en giltig port.")
                log.append(f"Port {port_str} - giltig")
            else:
                print(f"{port_str} är inte en giltig port.")
                log.append(f"Port {port_str} - ogiltig")

        elif choice == "3":
            show_log(log)

        elif choice == "4":
            print(f"Totalt antal valideringar: {len(log)}")
            print("Avslutar.")
            break

        else:
            print("Ogiltigt val.")

## Kör programmet

if __name__ == "__main__":
    main()
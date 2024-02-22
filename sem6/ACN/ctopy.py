def BtoD(a):
    binary = ""

    while a > 0:
        remainder = a % 2
        digit = '0' + str(remainder)
        binary = digit + binary
        a = a // 2

    # Pad with leading zeros to make it 8 bits
    while len(binary) < 8:
        binary = '0' + binary

    return binary


arr = [0] * 4
index = 0
customSMN = 0
className = ''

def class_in_binary():
    result = ""
    for i in range(index):
        result += BtoD(arr[i])
        if i < index - 1:
            result += '.'  # Add dot between octets
    print("\tClass in Binary:", result)


def binary_to_decimal(ip):
    global index, customSMN, className
    octet = ""
    for i in range(len(ip)):
        if ip[i] == '.':
            arr[index] = int(octet)
            index += 1
            octet = ""
        else:
            if ip[i] == '/':
                customSMN = int(ip[i + 1:])
            octet += ip[i]

    arr[index] = int(octet)
    index += 1

    if 1 <= arr[0] <= 126:
        print("\tClass A address")
        className = 'A'
    elif 128 <= arr[0] <= 191:
        print("\tClass B address")
        className = 'B'
    elif 192 <= arr[0] <= 223:
        print("\tClass C address")
        className = 'C'
    print()


def network_and_host_addr():
    if className == 'A':
        print("\tNetwork ID:", arr[0])
        print("\tNetwork Address:", f"{arr[0]}.0.0.0")
        print("\tHost ID:", f"{arr[1]}.{arr[2]}.{arr[3]}")
        print("\tHost Address:", f"0.{arr[1]}.{arr[2]}.{arr[3]}")
    elif className == 'B':
        print("\tNetwork ID:", f"{arr[0]}.{arr[1]}")
        print("\tNetwork Address:", f"{arr[0]}.{arr[1]}.0.0")
        print("\tHost ID:", f"{arr[2]}.{arr[3]}")
        print("\tHost Address:", f"0.0.{arr[2]}.{arr[3]}")
    elif className == 'C':
        print("\tNetwork ID:", f"{arr[0]}.{arr[1]}.{arr[2]}")
        print("\tNetwork Address:", f"{arr[0]}.{arr[1]}.{arr[2]}.0")
        print("\tHost ID:", arr[3])
        print("\tHost Address:", f"0.0.0.{arr[3]}")
    print()


def subnet_mask_addr():
    mask_add = "00000000000000000000000000000000"
    i = 0
    while customSMN > 0:
        mask_add[i] = '1'
        customSMN -= 1
        i += 1

    print("\tCustom Masking Address:", f"{int(mask_add[0:8], 2)}.{int(mask_add[8:16], 2)}.{int(mask_add[16:24], 2)}.{int(mask_add[24:32], 2)}")


def address_info():
    if className == 'A':
        print("\tFirst Address:", f"{arr[0]}.0.0.0")
        print("\tLast Address:", f"{arr[0]}.255.255.255")
        print("\tTotal Addresses:", 256 * 256 * 256)
    elif className == 'B':
        print("\tFirst Address:", f"{arr[0]}.{arr[1]}.0.0")
        print("\tLast Address:", f"{arr[0]}.{arr[1]}.255.255")
        print("\tTotal Addresses:", 256 * 256)
    elif className == 'C':
        print("\tFirst Address:", f"{arr[0]}.{arr[1]}.{arr[2]}.0")
        print("\tLast Address:", f"{arr[0]}.{arr[1]}.{arr[2]}.255")
        print("\tTotal Addresses:", 256)
    print()


if __name__ == "__main__":
    ip_addr = input("Enter an IPv4 address with CIDR No.: ")
    action = None

    while action != 0:
        print("Select an action:")
        print("1. Display Binary and Decimal Representation")
        print("2. Display Network and Host Addresses")
        print("3. Display Subnet Mask")
        print("4. Display Address Information")
        print("0. Exit")

        try:
            action = int(input("Enter the number corresponding to your choice: "))
        except ValueError:
            print("Invalid choice. Please enter a valid option.")
            continue

        if action == 1:
            print()
            binary_to_decimal(ip_addr)
            class_in_binary()
            print()
        elif action == 2:
            print()
            network_and_host_addr()
            print()
        elif action == 3:
            print()
            subnet_mask_addr()
            print()
        elif action == 4:
            print()
            address_info()
            print()
        elif action == 0:
            print("Exiting the program.")
            print()
        else:
            print("Invalid choice. Please enter a valid option.")
            print()


ipAddr = input("Enter the IP address: ")
ipAddr = ipAddr.split('.')

def checkValidate(ipAddr):
    # Check if the IP address has leading zero
    for i in ipAddr:
        if i[0] == '0':
            return "Error: Leading zero"
    # Check if the IP address has 4 octets
    if len(ipAddr) != 4:
        return "Error: Not 4 octets"
    # Check if the IP address has valid octets
    for i in ipAddr:
        if int(i) < 0 or int(i) > 255:
            return "Error: Not in range"
    # Check if the IP address has only digits
    for i in ipAddr:
        if not i.isdigit():
            return "Error: Not a digit"
    
    return True

def validateClass(ipAddr):
    # Check if the IP address is class A
    if int(ipAddr[0]) >= 1 and int(ipAddr[0]) <= 126:
        return "Class A"
    # Check if the IP address is class B
    elif int(ipAddr[0]) >= 128 and int(ipAddr[0]) <= 191:
        return "Class B"
    # Check if the IP address is class C
    elif int(ipAddr[0]) >= 192 and int(ipAddr[0]) <= 223:
        return "Class C"
    # Check if the IP address is class D
    elif int(ipAddr[0]) >= 224 and int(ipAddr[0]) <= 239:
        return "Class D"
    # Check if the IP address is class E
    elif int(ipAddr[0]) >= 240 and int(ipAddr[0]) <= 255:
        return "Class E"
    # Find the special class address
    else:
        if ipAddr[0] == '0':
            return "Special class address: Reserved IP address"
        
        elif ipAddr[0] == '127':
            return "Special class address: Loop-back addresses"
    

if checkValidate(ipAddr) == True:
    print("The IP address is valid")
    print("The IP address is of class", validateClass(ipAddr))
else:
    print(checkValidate(ipAddr))
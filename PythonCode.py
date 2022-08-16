FILENAME = "items.txt"

def readFile(filename):
    '''
    Gets the list of lines read in from the file in raw form.
    @param - the filename to read in (must be in same directory as the Source.cpp!)
    @return - the list of lines
    '''
    
    lines = None
    
    with open(FILENAME) as file:
        lines = file.readlines()

    return lines


def getInventory():
    '''
    Get the inventory read in from the file.
    @return - dictionary of inventory in the form {item : frequency}
    '''
    
    inventory = {}
    
    items = readFile(FILENAME)

    for item in items:
        
        item = item.strip() 

        # Updates existing frequency; otherwise adds item to dictionary
        if item in inventory:
            inventory[item] += 1
        else:
            inventory[item] = 1
            
    return inventory


def determineInventory():
    '''
    Prints each item of the inventory and how many times it sold in the file
    No param or return values
    '''

    inventory = getInventory()

    # Gathers the key:value pair when looping through and prints it
    for key, value in inventory.items():
        print((key + ":").ljust(14) + str(value))


def determineFrequency(item):
    '''
    Returns the corresponding value to the item to show how many times that item appeares in the file
    Param item: Item being searched for in the dictionary of items sold
    Return: Item's value meaning how many times that item was sold
    '''

    inventory = getInventory()

    if item in inventory.keys():
        return inventory[item]
    else:
        return 0
    

def output():
    '''
    Writes the result of getInventory to a file
    No param or return
    '''

    inventory = getInventory()

    f = open("frequency.dat", "w")
    
    for key, value in inventory.items():
        f.write("{} {}".format(key,value))

    f.close()

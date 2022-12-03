def convertItemToPriority(item):
    ascii = ord(item)
    priority = 0
    if ascii >= 65 and ascii <= 90:
        priority = ascii-64+26
    elif ascii >= 97 and ascii <= 122:
        priority = ascii-96
    return priority

# Read input
input = open("input.txt")
rucksacks = input.readlines()

# Solution 1
sumPriorities = 0
for rucksack in rucksacks:
    blackList = ""
    first_compartment = rucksack[slice(0, len(rucksack)//2)]                #First half of string
    second_compartment = rucksack[slice(len(rucksack)//2, len(rucksack))]   #Second half of string
    for item in first_compartment:
        if item in second_compartment and not item in blackList:
            blackList += item
            sumPriorities += convertItemToPriority(item)
print("Antwort 1: ", sumPriorities)

# Solution 2
sumPriorities = 0
currentRucksack = 0

rucksackGroup = []
for rucksack in rucksacks:
    blackList = ""
    currentRucksack += 1
    rucksackGroup.append(rucksack)
    if currentRucksack % 3 == 0:
        for item in rucksackGroup[0]:
            if item in rucksackGroup[1] and item in rucksackGroup[2] and not item in blackList:
                blackList += item
                sumPriorities += convertItemToPriority(item)  
        rucksackGroup = []
print("Antwort 2: ", sumPriorities)
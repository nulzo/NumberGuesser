import random

count = 3

def find(arr, num, count):
    for i in range(len(arr)):
        if arr[i] == num:
            return i
    return -1

def generate(generated, count=count):
    size = 0
    while size < count:
        randomNumber = random.randint(1, 9)
        generated[size] = randomNumber
        size += 1
    return generated

def getUserInput(arr, count=count):
    size = 0
    while size < count:
        userchoice = int(input("Enter a value between 1-9: "))
        found = find(arr, userchoice, count) == -1
        if found:
            arr[size] = userchoice
            size += 1
        else:
            print("Must enter non-duplicate value.")
    return arr

def findBalls(generated, arr):
    balls = 0
    for i in range(len(generated)):
        current = generated[i]
        index = find(arr, current, count)
        if index != -1 and index != i:
            balls += 1
    return balls

def findStrikes(generated, arr):
    strikes = 0
    for i in range(len(generated)):
        current = generated[i]
        index = find(arr, current, count)
        if index == i:
            strikes += 1
    return strikes

def main():
    generated = [0]*count
    generated = generate(generated)
    while True:
        userinput = [0]*count
        userinput = getUserInput(userinput)
        balls = findBalls(generated, userinput)
        strikes = findStrikes(generated, userinput)

        if strikes > 0:
            print(f"{strikes} strike(s)")
        if balls > 0:
            print(f"{balls} ball(s)")
        if balls == 0 and strikes == 0:
            print("Out")

        if strikes == count:
            choice = input ("Good Job! Do you want to play again (y/n)?: ").lower()
            while choice != "y" and choice != "n":
                print("Invalid input!")
                choice = input ("Do you want to play again (y/n)?: ").lower()
            if choice == "n":
                break
            generated = generate()
    return 0

if __name__ == "__main__":
    main()

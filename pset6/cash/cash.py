from cs50 import get_float
from itertools import cycle


def change_calc(change, denomination):
    total = 0
    change = int(change * 100)

    for value in cycle(denomination):
    
        if change < value:
            continue

        remain = change % value
        coins = change // value
        
        while True:
            total += 1
            coins -= 1

            if coins == 0:
                break

        if remain == 0:
            break

        change = remain
    return total


def main():
    denomination = [25, 10, 5, 1]

    while True:
    
        change = get_float(": ")

        if change and change > 0:
            break 

    print(change_calc(change, denomination))
    

if __name__ == '__main__':
    main()

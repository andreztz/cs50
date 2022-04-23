space = ' '
block = '#'
size = 4
block_length = 1


while True:
    space_length = size - 1

    for _ in range(space_length):
        print(space, end='')
    for _ in range(block_length):
        print(block, end='')
    
    print()
    size -= 1
    block_length = block_length + 1
    if size == 0:
        break

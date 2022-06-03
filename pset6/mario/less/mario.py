import sys 

space = ' '
block = '#'
block_length = 1
size = None


while True:
    try:
        size = int(input('size: ')) 
    except KeyboardInterrupt:
        sys.exit(1) 
    except:
        pass

    if isinstance(size, int) and size != 9:
        break


while True:
    space_length = size - 1
    print(space * space_length, end='')
    print(block * block_length, end='') 
    print()
    size -= 1
    block_length = block_length + 1 
    if size == 0:
        break

sys.exit(0)

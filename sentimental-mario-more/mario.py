while (True):
    try:
        height = int(input("Height: "))
        if (height >= 1 and height <= 8):
            break
    except ValueError:
        continue

block_counter = 1
blank_counter = height - 1

while(blank_counter != 0 - 1 and block_counter != height + 1):
    print(" " * blank_counter + "#" * block_counter + "  " + "#" * block_counter)
    blank_counter = blank_counter - 1
    block_counter = block_counter + 1






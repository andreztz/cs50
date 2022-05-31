#!/usr/bin/env python
"""
Open memory card
Repeat until end of card
    Read 512 bytes into a buffer
    If start of new JPEG
        IF start first JPGE
            ...
        Else 
            ...

    else 
        if already found JPEG
            ...

Close any remaining files

[List of file signatures](https://en.wikipedia.org/wiki/List_of_file_signatures)

"""
BLOCK_SIZE = 512


def is_jpeg_header(header):
    return (
        header[0] == 0xff
        and header[1] == 0xd8
        and header[2] == 0xff
        and header[3] & 0xf0 == 0xe0
    )


with open("card.raw", "rb") as file:
    counter = 0
    buffer = bytes()
    found = False
    while chunk := file.read(BLOCK_SIZE):
        if is_jpeg_header(chunk):
            if found:
                filename = f"{counter:03}.jpeg"
                with open(filename, "wb") as picture:
                    picture.write(buffer)
                counter += 1
            buffer = chunk
            found = True
        else:
            buffer += chunk



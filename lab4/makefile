all: clean compile

compile:
	clang -g volume.c -lcs50 -v -o volume   

clean:
	rm ./output.wav

check:
	check50 cs50/labs/2021/x/volume 

check-local:
	check50 --local cs50/labs/2021/x/volume 

style:
	style50 volume.c

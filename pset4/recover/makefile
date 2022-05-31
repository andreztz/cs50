all: clean compile

compile:
	clang recover.c -lcs50 -lm -o recover

clean:
	-rm recover
	-rm *.jpg

check:
	check50 cs50/problems/2021/x/recover

check-local:
	check50 --local cs50/problems/2021/x/recover

style:
	style50 recover.c

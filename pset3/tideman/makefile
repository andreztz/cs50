all: compile check-local 

compile:
	clang tideman.c -lcs50 -lm -o tideman  

check:
	check50 cs50/problems/2021/x/tideman

check-local:
	check50 --local cs50/problems/2021/x/tideman

clean:
	-rm tideman

style:
	style50 tideman.c

all: compile check-local 

compile:
	clang mario.c -lcs50 -o mario  

check:
	check50 cs50/problems/2021/x/mario/more

check-local:
	check50 --local cs50/problems/2021/x/mario/more

clean:
	-rm mario

style:
	style50 mario.c

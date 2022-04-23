all: compile check-local 

compile:
	clang population.c -lcs50 -lm -o population  

check:
	check50 cs50/labs/2021/x/population

check-local:
	check50 --local cs50/labs/2021/x/population

clean:
	-rm population

style:
	style50 population.c

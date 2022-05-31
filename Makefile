a.out: *.c
	gcc *.c -o a

clean:
	rm a.exe a.out a

test: a.out
	bash test.sh

eval: a.out
	bash eval.sh

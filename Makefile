CC = clang++
FLAGS=
STD=c++20

objs= test_lexer

test_lexer: Lexer/test_lexer.cpp
	$(CC) $(FLAGS) -std=$(STD) -o test_lexer Lexer/test_lexer.cpp

clean:
	$(RM) $(objs)
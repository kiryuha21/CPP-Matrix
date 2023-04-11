CC = g++

FLAGS = -Wall -Wextra -Werror -pedantic -std=c++17
LINK_LIBRARIES = -lgtest

SRC_C_FILES = lib/*.cpp
TEST_C_FILES = tests/*.cpp

TEST_TARGET = s21_test

LIB = s21_matrix_oop.a

all: clean test $(LIB)

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i $(wildcard */*.cpp *.cpp */*.h *.h)
	rm -f .clang-format

test: clang $(SRC_C_FILES) $(SRC_H_FILES)
	$(CC) $(FLAGS) $(SRC_C_FILES) $(TEST_C_FILES) -o $(TEST_TARGET) $(LINK_LIBRARIES)
	./$(TEST_TARGET)

$(LIB): clang
	$(CC) -c $(SRC_C_FILES) $(LINK_LIBRARIES)
	ar rcv $(LIB) *.o
	ranlib $(LIB)
	rm *.o

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

clean_test:
	rm -f $(TEST_TARGET)

clean_lib:
	rm -f $(LIB)

clean_obj:
	rm -f *.o

clean: clean_test clean_lib clean_obj

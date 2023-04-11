CC = g++

FLAGS = -Wall -Wextra -Werror -pedantic
LINK_LIBRARIES = -lgtest

SRC_C_FILES = lib/*.cpp
TEST_C_FILES = tests/*.cpp

TEST_TARGET = s21_test

LIB = s21_matrix_oop.a

REPORT_DIR = report

all: clean test gcov_report $(LIB)

apply_clang:
	cp ../materials/linters/.clang-format .
	clang-format -i *.h
	clang-format -i */*.cpp
	rm -f .clang-format

test: apply_clang $(SRC_C_FILES) $(SRC_H_FILES)
	$(CC) $(FLAGS) $(SRC_C_FILES) $(TEST_C_FILES) s21_matrix_oop.h -o $(TEST_TARGET) $(LINK_LIBRARIES)
	./$(TEST_TARGET)

gcov_report: apply_clang
	$(CC) --coverage $(FLAGS) $(SRC_C_FILES) $(TEST_C_FILES) -o $(TEST_TARGET) $(LINK_LIBRARIES)
	./$(TEST_TARGET)
	lcov -t "$(TEST_TARGET)" -o $(TEST_TARGET).info -c -d .
	genhtml -o report $(TEST_TARGET).info
	rm *.gcda *.gcno *.info
	open report/index.html

$(LIB): apply_clang
	$(CC) -c $(SRC_C_FILES) $(LINK_LIBRARIES)
	ar rcv $(LIB) *.o
	ranlib $(LIB)
	rm *.o

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

clean_test:
	rm -f $(TEST_TARGET)

clean_report:
	rm -rf $(REPORT_DIR)

clean_lib:
	rm -f $(LIB)

clean_obj:
	rm -f *.o

clean_gcov:
	rm -f *.gc*

clean: clean_test clean_report clean_lib clean_obj clean_gcov
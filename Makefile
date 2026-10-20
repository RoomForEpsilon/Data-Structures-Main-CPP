demo: bag.cpp bag.h bagDemo.cpp 
	c++ -std=c++17 -g -Werror -Wextra -Wall -Wpedantic -O0  -fsanitize=address,undefined -o demo bagDemo.cpp bag.cpp
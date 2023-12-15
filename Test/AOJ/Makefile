a.out: main.cpp
	g++ -std=c++20 -Wall -Wextra -O2 -I ~/compro/library -I ~/compro/cp-documentation -I ~/compro/ac-library main.cpp

debug: 3168.test.cpp
	g++ -std=c++17 -Wall -Wextra -O2 -D_GRIBCXX_DEBUG -g -fsanitize=undefined,address -fno-omit-frame-pointer -I ~/compro/library -I ~/compro/cp-documentation -I ~/compro/ac-library 3168.test.cpp


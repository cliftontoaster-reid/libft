if [ -d "libftTester" ]; then 
	cd libftTester
  git pull && git rebase
  cd .. 
else \
	git clone https://github.com/Tripouille/libftTester;
fi
sed -i 's/#include <limits.h>/#include <cstdint>\n#include <limits.h>/' libftTester/tests/ft_calloc_test.cpp
cd libftTester
make m
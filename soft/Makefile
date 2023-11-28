.PHONY: all fclean clean re

CXX          = g++
TARGET       = cuddly-couscous

SRC          = $(wildcard src/*.cpp)
CXXFLAGS += -Wall -Wextra -Wno-return-type -I./include -O2 -g -std=c++17
LDFLAGS  += -lncurses
LDLIBS    += -lpcap

OBJECTS      := $(SRC:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "LD 	$(TARGET)"
	@$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	@echo "CXX 	$<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(TARGET)
	@rm -rf *.gcda *.gcno
	@rm -rf vgcore*
	@rm -f logs/*.txt
	@echo "[OK]:	removed objects."

re: fclean all

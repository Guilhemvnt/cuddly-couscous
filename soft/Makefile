.PHONY: all fclean clean re

CXX          = g++
TARGET       = cuddly-couscous

SRC          = $(wildcard src/*.cpp)

CXXFLAGS     += -Wall -Wextra -Wno-return-type
CXXFLAGS     += -I./include -O2 -g3 -c
CXXFLAGS     += -std=c++17
CXXFLAGS     +=

LDFLAGS      =
LDLIBS       = -lpcap

OBJECTS      := $(SRC:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "LD 	$(TARGET)"
	@$(CXX) -o $@ $(LDFLAGS) $^ $(LDLIBS)

%.o: %.cpp
	@echo "CXX 	$<"
	@$(CXX) $(CXXFLAGS) $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f $(OBJECTS)
	@rm -f $(TARGET)
	@rm -rf *.gcda *.gcno
	@rm -rf vgcore*
	@echo "[OK]:	removed objects."

re: fclean all

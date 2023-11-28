g++ -o main main.cpp
g++ -o test_main test_main.cpp -lcriterion -lgmock -lgtest -pthread
./test_main
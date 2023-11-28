#!/bin/bash

# Update package manager
sudo apt update

# Install C++ development tools
sudo apt install g++

# Install C++ libraries
sudo apt install libncurses5-dev
sudo apt install libpcap-dev

# The following libraries are typically part of the standard C++ library
# and don't require separate installations on most systems.

#comment and adjust the following lines if necessary
sudo apt install libstdc++-dev
sudo apt install libc6-dev

echo "Installation complete."

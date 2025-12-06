#!/bin/bash

# Usage: ./Generator.sh [COUNT]
# Default = 300 numbers

COUNT=${1:-300}

numbers=$(shuf -i 1-100000 -n "$COUNT" | tr '\n' ' ')

echo "Running PmergeMe with $COUNT random numbers:"
echo "$numbers"
echo

./PmergeMe $numbers

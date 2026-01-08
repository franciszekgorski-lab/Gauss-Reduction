#!/bin/bash

for i in {1..10}; do
        echo "Test $i: T$i i T${i}b"
        ./bin/gauss dane/testowe/T$i dane/testowe/T${i}b
done

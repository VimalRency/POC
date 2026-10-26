

#!/bin/bash
echo "================================="
echo "Running CPPCHECK"
echo "================================="
cppcheck \
--enable=all \
--inconclusive \
--force \
--std=c11 \
.c .h
echo "================================="
echo "CPPCHECK COMPLETED"
echo "================================="









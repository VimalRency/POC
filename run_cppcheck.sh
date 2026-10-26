

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

chmod +x run_cppcheck.sh
./run_cppcheck.sh








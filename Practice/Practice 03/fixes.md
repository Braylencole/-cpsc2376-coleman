# Fixes for buggy code in the originial code of practice03's main.cpp file

# Sum Range

### 1. "Sum Range" was off by one. added the <= instead of < .

# Contains Negative

### 1.  "Contains Negative" was returning an out of bounds error. Corrected this by changing <= to < in the for loop. Now it checks for negative numbers correctly.
### 2.  "Contains Negative" Changed the if statement to check for less than zero.

# Find Max

### 1.  "Find Max" was returning an out of bounds error. Corrected this by changing <= to < in the for loop. Now it checks for the max number correctly.
### 2.  "Find Max" Changed the if statement to check for greater than the current max.
### 3.  "Find Max" Changed the return statement to return the max number.


# Summary

### The original code had a few errors in the functions. The errors were fixed by changing the for loop conditions and the if statements. The functions now work as intended.
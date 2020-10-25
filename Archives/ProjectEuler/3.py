import sys
from math import sqrt

def smallest_prime_factor(n):
    for i in range(2,int(sqrt(n))):
        if(n%i==0): return i
    return n

num = int(sys.argv[1])
while True:
    p = smallest_prime_factor(num)
    if p<num:
        num /= p
    else:
        print(p)
        break

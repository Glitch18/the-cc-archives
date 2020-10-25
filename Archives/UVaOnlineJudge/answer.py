import re
import sys

def FCL(x):
	if x in memory:
		return memory[x]
	else:
		a = x/2 if x%2==0 else 3*x+1
		memory[x]=FCL(a)+1
		return memory[x]

memory = {1:1}
full_input = sys.stdin.read()
full_input = full_input.split('\n')

for line in full_input:
    if line == '': continue
    #numbers = line.split(" ")
    numbers = re.findall(r'[\d.]+', line)
    output = " ".join(numbers)
    maximum=0
    numbers=[int(x) for x in numbers]
    numbers.sort()
    for i in range(int(numbers[0]),int(numbers[1])+1):
        ans = FCL(i)
        if(ans>maximum): maximum=ans
    print(output+" "+str(maximum))



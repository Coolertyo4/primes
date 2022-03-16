import os
primes = []

for i in range(10000):
    if os.system("./app -r -c  -n " + str(i)) == 1:
        primes.append(i)

for prime in primes:
    print(prime)
        
MAX = 100000

def sieve():
    is_prime = [True] * (MAX + 1)
    is_prime[0] = is_prime[1] = False
    primes = []
    
    for i in range(2, MAX + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, MAX + 1, i):
                is_prime[j] = False
                
    return is_prime, primes

is_prime, primes = sieve()

t = int(input())

for _ in range(t):
    n = int(input())
    for m in primes:
        if not is_prime[n + m]:
            print(m)
            break

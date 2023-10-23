def fib(n: int) -> int:
    assert n >= 0

    fibs = [0, 1]
    for i in range(2, n + 1):
        fibs.append(fibs[i - 1] + fibs[i - 2])

    return fibs[n]


assert fib(2) == 1
assert fib(3) == 2
assert fib(4) == 3
assert fib(5) == 5
assert fib(6) == 8
assert fib(7) == 13
assert fib(8) == 21
assert fib(9) == 34
assert fib(10) == 55
assert fib(11) == 89
assert fib(12) == 144
assert fib(13) == 233
assert fib(14) == 377
assert fib(15) == 610

print("All tests passed!")

def perms(a, k, i):
    for j in range(k):
        a[i] = j
        if valid(a, i, k):
            if i + 1 == k:
                print(a)
            else:
                perms(a, k, i + 1)

def valid(a, index, k):
    for i in range(index):
        if a[i] == a[index]:
            return False
    return True

def real(a):
    return len(a) == len(set(a))

perms([0 for _ in range(3)], 3, 0)
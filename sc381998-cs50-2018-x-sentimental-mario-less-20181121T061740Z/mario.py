import cs50
while True:
    print("Height: ",end=" ")
    n=cs50.get_int()
    if n>=0 and n<=23:
        break


for i in range(n):
    print(' ' *(n-1-i), end=" ")
    print('#' *(i+2))
import cs50
import sys
def main():
    if len(sys.argv)!=2:
        print("Usage python caesar.py key")
        exit(1)
    k=int(sys.argv[1]);
    plaintext=cs50.get_string()
    for c in plaintext:
        if(c.islower()):
            print( chr((ord(c)-ord('a')+k)%26+ord('a')),end="")
        elif(c.isupper()):
            print( chr((ord(c)-ord('A')+k)%26+ord('A')), end="")
        else:
            print(c,end="")

    print()

if __name__=="__main__":
    main()


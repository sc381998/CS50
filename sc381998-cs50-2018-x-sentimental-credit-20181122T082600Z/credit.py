import cs50

def main():
    while True:
        print("Number: ", end=" ")
        credit_card=cs50.get_int()
        if(credit_card>=0):
            break
    check_validity(credit_card)

def check_validity(ccn):
    length=get_length(ccn)
    if(checklength(length)==True and checksum(ccn, length)==True)==False:
        print("INVALID")
        return
    print_card_brand(ccn)
def get_length(n):
    length=0
    while n>0:
        length=length+1
        n=n // 10
    return length
def checklength(length):
    if(length==13 or length==15 or length==16):
        return True
    return False
def checksum(ccn, length):
    summation = 0
    for i in range(length):
        if(i%2==0):
            summation=summation + (ccn%10)
        else:
            digit=2*(ccn%10)
            summation=summation + (digit // 10 + digit % 10)
        ccn=ccn//10
    if(summation %10==0):
        return True
    return False

def print_card_brand(ccn):
    if((ccn>=340000000000000 and ccn<350000000000000) or (ccn>=370000000000000 and ccn<=380000000000000)):
        print("AMEX")
    elif (ccn>=5100000000000000 and ccn<=5600000000000000):
        print("MASTERCARD")
    elif((ccn>=4000000000000000 and ccn<=5000000000000000) or (ccn>=4000000000000000 and ccn<=5000000000000000)):
        print("VISA")
    else:
        print("INVALID")

if __name__ =="__main__":
    main()
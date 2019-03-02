def lines(a, b):
    return list(set(a.split('\n')).intersection(b.split('\n')))

from nltk.tokenize import sent_tokenize

def sentences(a, b):
    return list(set(sent_tokenize(a)).intersection(sent_tokenize(b)))


def substrings(a, b, n):
    return list(set([a[i: i+n] for i in range(len(a)-(n-1))]).intersection([b[i: i+n] for i in range(len(b)-(n-1))]))

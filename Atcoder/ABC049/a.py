c = raw_input()
boin = ["a", "i", "u", "e", "o"]
for i in xrange(5):
    if c in boin[i]:
        print "vowel"
        break
    if i == 4:
        print "consonant"

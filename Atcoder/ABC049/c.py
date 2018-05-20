S = raw_input()
S.replace("a","sine")
if "eraser" in S:
    S=S.replace("eraser", "")
if "erase" in S:
    S=S.replace("erase", "")
if "dreamer" in S:
    S=S.replace("dreamer", "")
if "dream" in S:
    S=S.replace("dream","")
print "YES" if len(S)==0 else "NO"

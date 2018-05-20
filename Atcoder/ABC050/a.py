str = raw_input().split()
print int(str[0]) + int(str[2]) if str[1] == "+" else int(str[0]) - int(str[2])

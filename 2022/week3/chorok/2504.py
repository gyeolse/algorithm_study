brackets = input()
stack = []
temp = 1
result = 0

for i in range(len(brackets)):
    if brackets[i] == '(':
        temp *= 2
        stack.append(brackets[i])
    elif brackets[i] == '[':
        temp *= 3
        stack.append(brackets[i])
    elif brackets[i] == ')':
        if not stack or stack[-1] == '[':
            result = 0
            break
        if brackets[i-1] == '(':
            result += temp
        temp //= 2
        stack.pop()
    else:
        if not stack or stack[-1] == '(':
            result = 0
            break
        if brackets[i-1] == '[':
            result += temp
        temp //= 3
        stack.pop()

if stack:
    result = 0
print(result)
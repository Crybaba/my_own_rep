a= str(input('Введите последовательность:'))
A=[]
C=[]
E=[]
c=str()
for k in a:
    if k=='.':
        A += [c]
        break
    if k== ',':
        A+=[c]
        c=''
    if k != ',':
        c = c+k

B=['у','е','а','о','э','я','и','ю','ы','ё']
D=['б','в','г','д','ж','з', 'л', 'м', 'н', 'р', 'й']
for x in B:
    c=1
    for y in range(len(A)):
        if x not in A[y]:
            c=0
    if c==1 and x not in C:
        C+=[x]

print('a) Ответ:', end='')
for l in C:
    print('', l, end =',')
print('')

for x in D:
    c=1
    for y in range(len(A)):
        if y%2==0 and x not in A[y]:
            c=0
        if y%2!=0 and x in A[y]:
            c=0
    if c==1 and x not in E:
            E+=[x]
print('b) Ответ:', end='')
for l in E:
    print('', l, end =',')

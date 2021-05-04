
def report(xs):
    result=""
    total=0
    countscore=0
    i=0
    while i < len(xs):
        count=0
        names=[]
        if isinstance(xs[i], int):
            total=total+xs[i]
            countscore=countscore+1
            i=i+1
        if i==len(xs):
            break
        while isinstance(xs[i], str):
            names.append(xs[i])
            count=count+1
            i=i+1
        if i==len(xs):
            break
        if count>0:
            size=count-1
            for j in range(0,count-1):
                if size>1:
                    result=result+names[j]+" "
                    size=size-1
                elif size==1:
                    result=result+names[j]+", "
    avg=total/countscore
    result=result+"averaged "+str(avg)+"."
    return result
            

print(report(["Jill","Johnson",87,"Billy","Ray","Cyrus",78,"Rita","Yeats",94,"Bobbie","Sue","Palmer",72]))
print(report(["Fay","Hannah", "Rose",58,"Jillian","Murray",45,"Samrita","Kapoor",99]))

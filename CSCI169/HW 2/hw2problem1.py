
INPUT_SIZE = 10

## A simple print function
def printfunction(inputlist):
    for i in range(INPUT_SIZE):
        print(inputlist[i], end = " ")
    print()

## The partition function
def partition(inputlist, p, r):
    pivot = inputlist[r]
    while (p < r):
        while (inputlist[p] < pivot):
            p = p+1
        while (inputlist[r] > pivot):
            r = r-1
        if (inputlist[p] == inputlist[r]):
            p = p+1
        elif (p < r):
            tmp = inputlist[p]
            inputlist[p] = inputlist[r]
            inputlist[r] = tmp
    return r

## The quicksort recursive function
def quicksort(inputlist, p, r):
    if (p < r):
        j = partition(inputlist, p, r)
        quicksort(inputlist, p, j-1)
        quicksort(inputlist, j+1, r)

inputlist = [500, 700, 800, 100, 300, 200, 900, 400, 1000, 600]
print("Input: ", end = "")
printfunction(inputlist)
quicksort(inputlist, 0, 9);
print("Output: ", end= "")
printfunction(inputlist)

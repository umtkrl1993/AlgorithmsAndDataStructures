
class SortObj():

    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __gt__(self, other):
        return isinstance(other, SortObj) and self.key > other.key
    
    def __lt__(self, other):
        return isinstance(other, SortObj) and self.key < other.key

def swap(arr, i, r):
    temp = arr[i]
    arr[i] = arr[r]
    arr[r] = temp


def insertionSort(arr, low, high):

    for i in range(low+1, high+1):
        key = arr[i]

        j = i-1

        while arr[j] > key and j >=0:
            arr[j+1] = arr[j]
            j -= 1

        arr[j+1] = key


def selectionSort(arr, low, high):

    for i in range(low,high):
        min = i 
        for j in range(i+1, high+1):
            if arr[j] < arr[min]:
                min = j

        swap(arr,i,min)





def insertionSortWithIndex(arr, low, high):

    index_arr = [ i for i in range(low, high+1)]

    for i in range(low+1, high+1):
        key = arr[index_arr[i]]
        j = i - 1

        while arr[index_arr[j]] > key and j >= 0:
            index_arr[j+1] = index_arr[j]
            j -= 1

        index_arr[j+1] = i

    return index_arr

    
import pdb
def merge(arr, low, middle, high):
    A = [arr[i] for i in range(low,middle+1)]
    B = [arr[i] for i in range(middle+1,high+1)]
   
  #  pdb.set_trace()
    a = 0
    b = 0
    for i in range(low, high+1):

        if a >= len(A):
            arr[i] = B[b]
            b += 1

        elif b >= len(B):
            arr[i] = A[a]
            a += 1
        elif a < len(A) and A[a] < B[b]:
            arr[i] = A[a]
            a += 1

        else :
            arr[i] = B[b]
            b += 1


def merge_second_version(arr, low, middle, high):
    
    index = low
    aux = []
    while index <= middle:
        aux.append(arr[index])
        index += 1

    last = high
    while index <= high:
        aux.append(arr[last])
        index += 1
        last -= 1


def mergeSort( arr, low, high):

    if low >= high:
        return

    middle = (low+high) / 2

    mergeSort( arr, low, middle)
    mergeSort( arr, middle+1, high)
    merge(arr, low, middle, high)


def merge_sort_bottomUP(arr, low, high):
   # pdb.set_trace()
    number_of_access = 0
    N = high-low+1
    sz = 1

    while sz < N:
        lo = 0
        while lo < N-sz:
            merge(arr, lo, lo+sz-1, min(lo+sz+sz-1, N-1))
            lo += sz+sz
        sz = sz+sz

    """
    for sz in range(1, N, sz+sz-1):

        for lo in range(0, N-sz, sz+sz):
            merge(arr, lo, lo+sz-1, min(lo+sz+sz-1, N))

    """


if __name__ == "__main__":
    arr = [10,8,20,16,14,30]


    arr_rand = [10,8,12,8,12,10,12,10,8]

   # insertionSort(arr, 0, len(arr)-1)

    merge_sort_bottomUP(arr,0, len(arr)-1)

    print arr

  #  index_arr = insertionSortWithIndex(arr, 0, len(arr)-1)

   # mergeSort(arr_rand, 0, len(arr_rand)-1)

    #print(str(index_arr))
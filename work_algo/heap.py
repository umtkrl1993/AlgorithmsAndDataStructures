

class HeapNode():
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __lt__(self, other):
        return isinstance(other, HeapNode) and self.key < other.key

    def __le__(self, other):
        return isinstance(other, HeapNode) and self.key <= other.key

    def __gt__(self, other):
        return isinstance(other, HeapNode) and self.key > other.key
    
    def __ge__(self, other):
        return isinstance(other, HeapNode) and self.key >= other.key

    def __str__(self):
        return "key %s and value %s" %(self.key, self.value)




def swap(arr, i, j ):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp


def heapify(arr):
    arr_len = len(arr)

    index = arr_len - 1

    parent = int(index / 2)
    print("parent is %s" %parent)
    while index > 0 and arr[index] > arr[parent]:
        swap(arr, index, parent)
        index = parent
        parent = int(index/2)


def insertPQueue(arr, element):
    arr.append(element)
    heapify(arr)


def downHeap(arr, index = 1):
    
    biggest_index = index
    lc = biggest_index*2
    rc = biggest_index*2 + 1
    if arr[lc] > arr[biggest_index]:
        biggest_index = lc

    if arr[rc] > arr[biggest_index]:
        biggest_index = rc

    if biggest_index != index:
        swap(arr, biggest_index, index)
        downHeap(arr, biggest_index)



def _isMaxHeap(arr, index):
    
    if 2*index >= len(arr):
        return True

    if arr[index] < arr[2*index] or arr[index] < arr[2*index+1]:
        return False

    lr = _isMaxHeap(arr, 2*index)
    rr = _isMaxHeap(arr, 2*index+1)

    return ( lr and rr )


def isMaxHeap(arr):

    return _isMaxHeap(arr, 1)


def insertPQOrdered(arr, element):

    index = -1

    for i in range(0, len(arr)-1):
        if arr[i] < element and arr[i+1] > element:
            index = i
            break

    if index == -1:
        arr.append(element)

    else:

        arr.append(-1)
        for i in range(len(arr)-1, index+1, -1):
            arr[i] = arr[i-1]

        arr[index+1] = element


    

def extractMax(arr):
    if len(arr) > 0:
        max = arr[1]
        swap(arr, 1, len(arr)-1)
        arr.pop(-1)
        downHeap(arr,1)





if __name__ == '__main__':
   
    stack = []

    insertPQueue(stack, HeapNode(0, 299))
    insertPQueue(stack, HeapNode(1,100))
    insertPQueue(stack, HeapNode(2,200))
    insertPQueue(stack, HeapNode(3,50))
    insertPQueue(stack, HeapNode(4,400))
    insertPQueue(stack, HeapNode(10,200))
    insertPQueue(stack, HeapNode(6,400))
    insertPQueue(stack, HeapNode(7,400))

    temp = [1,2,3,4,5,6]

    for i in range(0, len(stack)):
        print(stack[i].key)

    print(isMaxHeap(stack))

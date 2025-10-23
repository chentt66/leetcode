def selectionSort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr


def mergeSortedArrays(a, b):
    # O(n + m)
    i = 0
    j = 0
    merged_array = []
    while (i < len(a)) and (j < len(b)):
        if a[i] <= b[j]:
            merged_array.append(a[i])
            i += 1
        else:
            merged_array.append(b[j])
            j += 1
    merged_array.extend(a[i:])
    merged_array.extend(b[j:])
    return merged_array

def mergeSort(arr):
    #  O(n log n)
    if len(arr) <= 1:
        return arr
    mid_idx = len(arr) // 2
    left = arr[:mid_idx]
    right = arr[mid_idx:]
    sorted_left = mergeSort(left)
    sorted_right = mergeSort(right)
    return mergeSortedArrays(sorted_left, sorted_right)

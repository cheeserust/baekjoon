def solution(array):
    freq = {}
    for i in array:
        if i in freq:
            freq[i] += 1
        else:
            freq[i] = 1
    max_freq = max(freq.values())
    arr_max = [k for k, v in freq.items() if v == max_freq]
    if len(arr_max) > 1: 
        return -1
    else:
        return arr_max[0]
    return answer
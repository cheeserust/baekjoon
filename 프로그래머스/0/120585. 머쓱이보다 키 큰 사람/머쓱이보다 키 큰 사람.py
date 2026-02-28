def solution(array, height):
    count =0
    for val in array:
        if val > height:
            count+=1
    return count
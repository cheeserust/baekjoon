def solution(array, n):
    answer = 0
    for val in array:
        if val == n:
            answer += 1
    return answer
def solution(str1, str2):
    lst = ""
    
    for i in range(len(str1)):
        lst += (str1[i])
        lst += str2[i]
    answer = str(lst)
    return answer
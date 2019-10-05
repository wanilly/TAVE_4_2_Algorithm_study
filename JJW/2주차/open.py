def solution(record):
    answer = []
    database = {}
    for word in record:
        temp = word.split(' ')
        command = temp[0]
        if command == "Enter":
            database[temp[1]] = temp[2]
        elif command == "Change":
            database[temp[1]] = temp[2]
    for word in record:
        temp = word.split(' ')
        target = database[temp[1]]
        command = temp[0]
        if command == "Enter":
            target += "님이 들어왔습니다."
        elif command == "Leave":
            target += "님이 나갔습니다."
        else:
            continue
        answer.append(target)
    return answer

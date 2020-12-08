def canUnlockAll(boxes):
    keys = [0]
    for j in keys:
        for i in boxes[j]:
            if i not in keys:
                keys.append(i)
            if len(keys) == len(boxes):
                return True
    return False

#!/usr/bin/python3


def canUnlockAll(boxes):
    if not isinstance(boxes, list):
        return False
    if len(boxes) == 0 or len(boxes) == 1:
        return True
    keys = [0]
    for j in keys:
        if len(boxes) > j >= 0:
            for i in boxes[j]:
                if i not in keys:
                    keys.append(i)
                if len(keys) == len(boxes):
                    return True
    return False

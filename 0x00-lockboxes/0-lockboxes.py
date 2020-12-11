#!/usr/bin/python3


def canUnlockAll(boxes):
    if not isinstance(boxes, list) or len(boxes) == 0:
        return False
    for box in boxes:
        if not isinstance(box, list):
            return False
    if len(boxes) == 1:
        return True
    keys = [0]
    for j in keys:
        for i in boxes[j]:
            if 0 < i < len(boxes) and i not in keys:
                keys.append(i)
            if len(keys) == len(boxes):
                return True
    return False

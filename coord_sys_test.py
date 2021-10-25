import turtle
import math
import time

t = turtle.Turtle()
x = [0, 100, 0, 0]
y = [0, -100, 0, 100]
t_a = 0


def distance(o_x, o_y):
    return math.sqrt(o_x ** 2 + o_y ** 2)


def angle(o_x, o_y, d):
    global t_a
    # correct
    if o_x > 0 and o_y > 0:
        return math.acos(o_x / d) / math.pi * 180
    # correct
    elif o_x > 0 and o_y < 0:
        return -math.acos(o_x / d) / math.pi * 180
    # correct
    elif o_x < 0 and o_y > 0:
        return 180 - math.acos(o_y / d) / math.pi * 180
    # correct
    elif o_x < 0 and o_y < 0:
        return -(90 + math.acos(o_y / d) / math.pi * 180)
    # correct
    elif o_x == 0 and o_y < 0:
        return -90
    # correct
    elif o_x == 0 and o_y > 0:
        return 90
    # correct
    elif o_y == 0 and o_x < 0:
        return -180
    # correct
    elif o_y == 0 and o_x > 0:
        return 0


def move(o_x, o_y):
    global t, t_a
    d = distance(o_x, o_y)
    a = angle(o_x, o_y, d)
    t_a = a - t_a
    print(t_a)
    t.left(t_a)
    t_a = a
    t.forward(d)


for i in range(1, len(x)):
    move(x[i] - x[i - 1], y[i] - y[i - 1])
    time.sleep(1)
time.sleep(5)

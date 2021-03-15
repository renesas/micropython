import uos

uos.listdir()

# ['boot.py', 'main.py']

uos.statvfs("/flash")

# (512, 512, 38, 25, 25, 0, 0, 0, 0, 255)
#             ^   ^
#             |   remaining = 512 x 25 = 12.5KB
#             + total = 512 x 38 = 19KB


f = open("main.py", "r")
f.read()
f.close()

import sys
import os

GCC="g++ -std=c++11"
GLAD="glad.c"
FLAGS="-lglfw3 -LGL -lX11 -lXrandr -lpthread -lXi"
if __name__ == "__main__":
    i = sys.argv[1]
    if len(sys.argv) < 3:
        os.system(f"{GCC} {GLAD} {i} {FLAGS}")
    else:
        o = sys.argv[2]
        os.system(f"{GCC} {GLAD} {i} -o {o} {FLAGS}")


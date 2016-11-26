# Liang-Barsky line clipping
> Program to implement **Liang-Barsky** line clipping algorithm.

### Compile

#### For linux
```
$ g++ liang_barsky.cpp -lGL -lGLU -lglut -o liang_barsky.o
```

#### For macOS
```
g++ liang_barsky.cpp -framework OpenGL -framework GLUT -o liang_barsky.o
```

### Run

#### Example 1
```
$ ./liang_barsky.o
Enter end points, P1(x1, y1) and P2(x2, y2): 45 55 245 255
```

![Example 1 Screenshot](ss1.png)  

#### Example 2
```
$ ./liang_barsky.o
Enter end points, P1(x1, y1) and P2(x2, y2): 125 245 150 60
```

![Example 1 Screenshot](ss2.png)

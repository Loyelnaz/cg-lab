# Liang-Barsky line clipping
> Program to implement **Liang-Barsky** line clipping algorithm. Control points are supplied through keyboard

### Formula

 Bezier curve formula for points P0(x0, y0), P1(x1, y1), P2(x2, y2) and P3(x3, y3)

![Formula Screenshot](formula.png)

### Compile

#### For linux
```
$ g++ bezier_curve.cpp -lGL -lGLU -lglut -o bezier_curve.o
```

#### For macOS
```
g++ bezier_curve.cpp -framework OpenGL -framework GLUT -o bezier_curve.o
```

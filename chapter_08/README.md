# Hot-swappable code
## Static and dynamic libraries

### Bank Vault

### Gym

### Exercises

#### Sharpen your pencil 0
![The angle brackets should be double quotes]("htpps://github.com/DaviNakamuraCardoso/c/chapter_08/images/ex0.png")

#### Sharpen your pencil 1
1. Start by creating an object file called *hfcal.o*; The *hfcal.o* header is
going to be stored in *./includes*:
```makefile
hfcal.o: hfcal.h hfcal.c
    gcc -c hfcal.c -I./includes -o hfcal.o
```
2. Next, they need to create a program called *elliptical.o* from the *elliptical.c*
test program
```makefile
elliptical.o: elliptical.c
    gcc -I./includes -c elliptical.c -o elliptical.o

```
3. Now, you need to create an archive library from *hfcal.o* and store it in *./libs*
```makefile
./libs/libhfcal.a: hfcal.o
    ar -rcs ./libs/libhfcal.a hfcal.o

```

4. Finally,  create the *elliptical* executable from *elliptical.o* and the *hfcal* archive
```makefile
elliptical: elliptical.o ./libs/libhfcal.a
    gcc elliptical.o  -I./includes -L./libs -lhfcal -o elliptical

```

#### Long Exercise 02
1. Assuming that you are already in the same directory as the hfcal_UK.c file and that you have write permissions on all the directories, what commands would you need to type to compile this new version of the library?

```makefile
gcc -fPIC -c hfcal_UK.c -o hfcal_UK.o
gcc -shared hfcal_UK.o -o /usr/local/lib/libhfcal.so

```
2. If the treadmill’s main application is called /opt/apps/treadmill, what would you need to type in to run the program?
```makefile
/opts/apps/treadmill
```

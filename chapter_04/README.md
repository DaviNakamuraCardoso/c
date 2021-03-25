# Break it down, build it up
## Using multiple source files

### Exercises
#### Be the compiler

```
float mercury_day_in_earth_days();
int hours_in_an_earth_day();

int main()
{
float length_of_day = mercury_day_in_earth_days();
int hours = hours_in_an_earth_day();
float day = length_of_day * hours;
```


- [x] You can compile the code
- [ ] You should display a warning
- [x] The program will work

```
float mercury_day_in_earth_days();

int main()
{
float length_of_day = mercury_day_in_earth_days();
int hours = hours_in_an_earth_day();
float day = length_of_day * hours;
```

- [x] You can compile the code
- [x] You should display a warning
- [x] The program will work


```
int main()
{
float length_of_day = mercury_day_in_earth_days();
int hours = hours_in_an_earth_day();
float day = length_of_day * hours;

```
- [ ] You can compile the code
- [x] You should display a warning
- [ ] The program will work

```
float mercury_day_in_earth_days();
int hours_in_an_earth_day();
int main()
{
int length_of_day = mercury_day_in_earth_days();
int hours = hours_in_an_earth_day();
float day = length_of_day * hours;

```
- [x] You can compile the code
- [ ] You should display a warning
- [ ] The program will work

#### Long exercise
##### Control engine
- [ ] thruster.c
- [ ] turbo.c
- [ ] graticule.c
- [ ] servo.c
- [ ] thruster.o
- [ ] turbo.o
- [x] graticule.o
- [x] servo.o
- [x] ems

##### Galley
- [ ] microwave.c
- [ ] popcorn.c
- [ ] juicer.c
- [ ] microwave.o
- [ ] popcorn.o
- [ ] juicer.o
- [x] galley

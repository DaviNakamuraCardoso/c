# Learning C
[toc]

Learning C by using the book *[Head First C](https://www.amazon.com/Head-First-C-Brain-Friendly-Guide/dp/1449399916)*, by David Griffiths and Dawn Griffiths


## Chapter 01: Diving in
### Getting started with C

#### Exercises

##### Sharpen your pencil
1. Prints *"The deck is hot. Increase bet."* to the console.
2. Prints *"I must not write code in class"* 10 times.
3. Gets a boyfriend name and prints the message: "Dear $name.\n\n You are history."
4. Prints *"Hearts"*


##### Code Magnets
```c
/*
* Program to evaluate face values.
* Released under the Vegas Public License.
* (c)2014 The College Blackjack Team.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char card_name[3];
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    int val = 0;

    if (card_name[0] == 'K') {
    val = 10;
    } else if (card_name[0] == 'Q') {
        val = 10;
    } else if (card_name[0] == 'J') {
        val = 10;
    } else if (card_name[0] == 'A')
    {
        val = 11;
    } else {
        val = atoi(card_name);
    }
    printf("The card value is %i\n", val);

    return 0;
}

```


##### Be the compiler
A. Won't compile
B. Will run as intended
C. Won't compile
D. Won't compile


##### Code mojo
| Code | Output     |
| :------------- | :------------- |
| ```y = x - y;```       | ```00 11 21 32 42```       |
| ```y = y + x;``` | ```00 11 23 36 410```|
| ```y = y + 2; \n if (i > 4)\n y = y - 1;```| ```02 14 25 36 47```|
| ```x = x + 1; \n y = y + x``` | ```11 34 59``` |
| ```if (y < 5) {x = x + 1; if (y < 3) {x = x - 1;}}``` | ```02 14 36 48``` |

## Chapter 02: What are you Pointing at?
### Memory and pointers


#### Project: *Head First Lounge Stock Tracker*
##### Pseudocode
- We’ll start with 30 bottles - that’s about 180 glasses
- While there’s still some fizz:
- Display the current stock
- Enter the number of glasses ordered
- Adjust the stock
- Then just go round again
#### Problems

##### Code magnets

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int stock = 180;
    char order_string[3];
    int order;

    while (stock > 0)
    {
        printf("The current stock is: %i\n", stock);
        scanf("%2s", order_string);

        order = atoi(order_string);
        stock = stock - order;

        printf("You ordered %i glasses\n", order);
    }
    puts("We are out of stock, baby!\n");

    return 0;
}

```
##### What's my purpose?
1. strchr: Find the location of a character inside a string
2. strcmp: Compare two strings together
3. strstr: Find the location of a string inside another string  
4. strcpy: Find the length of a string
5. strcat: Concatenate two strings together  

##### Sharpen your pencil
Wich of the functions above should you use for the jukebox program?
strstr

##### What's your hunch?

- [x] The string can't be updated
- [ ] We're swapping characters outside the string
- [ ] The string isn't in memory
- [ ] Something else

##### Code magnets
```c
void print_reverse(char* s)
{
    size_t len = strlen(s);
    char* t = s + len -1;
    while (t >= s)
    {
        printf("%c", *t);
        t = t - 1;

    }
    puts(" ");
}

```

##### C-Cross
1. mulberry
2. yrrebwarts
3. sharonfruit
4. tiurfiwik
5. blueberry
6. yrrebkcalb
7. starfruit
8. tiurfilgu

## Chapter 03: Do one thing and do it well
### Creating small tools
In this chapter we will build a program that parses data from CSV to JSON

#### Problems

##### Pool Puzzle
```c
#include <stdio.h>

int main(void)
{
    float latitude;
    float longitude;
    char info[80];

    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
    {
        if ((latitude > 26) && (latitude < 34))
        {
            if ((longitude > -76) && (longitude < -64))
            {
                printf("%f,%f,%s", latitude, longitude, info);
            }

        }
    }
    return 0;

}

```

#### TOP SECRET
Message 1: *The submarine will surface at 9PM*
Message 2: *Buy six eggs and some milk*

```html

<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="initial-scale=1.0, user-scalable=no">
    <meta charset="utf-8">
    <title>Head First C Map</title>
    <style>
      html, body {
        height: 100%;
        margin: 0;
        padding: 0;
      }
      #map {
        height: 100%;
      }
    </style>
  </head>
  <body>

    <script src="output.json" type="text/javascript">
    </script>
    <script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=false">
                 </script>

    <div style="overflow:hidden;height:100%;width:100%;">
      <div id="gmap_canvas" style="height:100%;width:100%;"></div>
      <style>#gmap_canvas img{max-width:none!important;background:none!important}</style>
                 </div>
    <script type="text/javascript">
function init_map(){
    var c_lat = 0;
    var c_lon = 0;
    for (var i = 0; i < data.length; i++) {
        c_lat += data[i].latitude;
        c_lon += data[i].longitude;
    }
    if (data.length > 0) {
        c_lat /= data.length;
        c_lon /= data.length;
    }

    var myOptions = {zoom:14,center:new google.maps.LatLng(c_lat,c_lon),mapTypeId: google.maps.MapTypeId.ROADMAP};
    map = new google.maps.Map(document.getElementById("gmap_canvas"), myOptions);

    for (var i = 0; i < data.length; i++) {
        (function fred(data, i) {
            var lat = data[i].latitude;
            if ((lat < -90) || (lat > 90)) {
              alert("Invalid latitude: '" + lat + "'");
              return;
            }
            var lng = data[i].longitude;
            if ((lng < -90) || (lng > 90)) {
              alert("Invalid longitude: '" + lng + "'");
              return;
            }
            var marker = new google.maps.Marker({map: map,position: new google.maps.LatLng(lat, lng)});
            var infowindow = new google.maps.InfoWindow({content:data[i].info });
            google.maps.event.addListener(marker, "click", function(){
                infowindow.open(map,marker);});
        })(data, i);
    }
}

google.maps.event.addDomListener(window, 'load', init_map);
   </script>
  </body>
</html>

```

## Chapter 04: Break it down, build it up
### Using multiple source files

#### Exercises
##### Be the compiler

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

#### Make magnets
```
oggswing: oggswing.c oggswing.h  
[TAB] gcc oggswing.c -o oggswing
swing.ogg: whitennerdy.ogg oggswing
[TAB] oggswing whitennerdy.ogg swing.ogg
```

## Chapter 05: Roll your own structures
### structs, unions and bitfields

### Problems

#### ~~Pool~~ Piranha Puzzle
```c
void catalog(struct fish f)
{
    printf("%s is a %s with %i teeth. He is %i\n",
        f.name, f.species, f.teeth, f.age
    );

    return;
}


int main(void)
{
    struct fish snappy = {"Snappy", "Piranha", 69, 4};
    catalog(snappy);

    return 0;
}

```


####  Long Exercise
```c
struct exercise
{
    const char* description;
    float duration;
};

struct meal
{
    const char* ingredients;
    float weight;
};

struct preferences
{
    struct meal food;
    struct exercise exercise;
};

struct fish
{
    const char* name;
    const char* species;
    int teeth;
    int age;
    struct preferences care;
}

```

0. How would you write this data in C?
```c
struct fish snappy = {"Snappy", "Piranha", 69, 4, {{"meat", 0.2}, {"swim in the jacuzzi", 7.5}}};

```
1. Complete the label function so it produces output like this:
```
Name:Snappy
Species:Piranha
4 years old, 69 teeth
Feed with 0.20 lbs of meat and allow to swim in the jacuzzi for 7.50 hours
```

```c
void label(struct fish a)
{
    printf("Name: %s\nSpecies: %s\n%i years old, %i teeth\n",
        a.name, a.species, a.teeth, a.age
    );
    printf("Feed with %2.2f libs of %s and allow to %s for %2.2f hours\n",
        a.care.food.weight, a.care.food.ingredients,
        a.care.exercise.description, a.care.exercise.duration
    );

}

```

#### Exercise
```c
#include <stdio.h>

typedef struct
{
    float tank_capacity;
    int tank_psi;
    const char* suit_material;
} equipment;

typedef struct scuba
{
    const char* name;
    equipment kit;
} diver;

void badge(diver d)
{
    printf("Name: %s Tank: %2.2f(%i) Suit: %s\n",
        d.name, d.kit.tank_capacity, d.kit.tank_psi, d.kit.suit_material);

    return;
}

int main(void)
{
    diver randy = {"Randy", {5.5, 3500, "Neoprene"}};
    badge(randy);

    return 0;
}
```

#### Mixed up mixes

1. ```c margarita m = {2.0, 1.0, {2}}```
2. ```c margarita m = {2.0, 1.0, {0.5}}```
3. ```c margarita m = {2.0, 1.0, {.lime_pieces=1}}```


#### Be the compiler
```c

margarita m = {2.0, 1.0, {0.5}};
```
[x] Compiles
[ ] Does not compile

```c
margarita m;
m = {2.0, 1.0, {0.5}};

```
[ ] Compiles
[x] Does not compile
*Explanation: if the declaration and the assignment are in different lines, the compiler thinks you are creating an array*


#### Exercise
```c
typedef struct
{
    unsigned int first_visit: 1;
    unsigned int come_again: 1;
    unsigned int fingers_lost: 4;
    unsigned int shark_attack: 1;
    unsigned int day_a_week: 3;
}

```

## Chapter 06: Building Bridges
### Data structures and Dynamic memory

#### Exercises
##### Sharpen your pencil
- Before:  
Amity -> Craggy -> Isla Nublar -> Shutter
                Skull

- After:
Amity -> Craggy -> Skull -> Isla Nublar -> Shutter

#### The big questions:
1. How many pieces of data were left in the heap?
1
2. What was the piece of data left in the heap?
A question (char*)
3. Which line (or lines) of code caused the leak?
```c
current->question = strdup(question);
```
*The pointer is set to a new location without releasing the old one*
4. How do you plug the leak?
```c
free(current->question);
current->question = strdup(question);

```
#### Project: Speller

##### Introduction
Solving the problem [speller](https://cs50.harvard.edu/x/2020/psets/5/speller/), the Problem Set 5 of [Harvard CS50x 2020](https://cs50.harvard.edu/x/2020/).
For this problem, given 1) a text file with all english words and 2) a text file the program should write a file with all the misspellings in the text, considering a misspelling as a word or expression that is not in the input 1.

##### Overview

To solve this problem in C, I used a [Trie](https://en.wikipedia.org/wiki/Trie) to store the words from the dictionary, since it's Big O notation is O(1) for this case;

Each node of the trie represent a character. In each trie, an unsigned int represents if the word exists or not

At the end of the search, the trie is released with a recursive function

## Chapter 07: Turn your functions up to 11
### Advanced functions

#### Code Magnets

```c
void find()
{
    int i;
    puts("Search results");
    puts("--------------------");

    for (i = 0; i < NUM_ADS; i++)
    {
        if (strstr(ADS[i], "sports") && !strstr(ADS[i], "bieber"))
        {
            printf("%s\n", ADS[i]);
        }
    }
    puts("--------------------");

    return;
}
```

#### Long Exercise
1. Find someone who likes sports but not bieber
2. Find someone who likes sports or workout
3. Find a non-smoker who likes theater
4. Find someone who likes theater arts or dining  

```c
unsigned int sports_no_bieber(char* s)
{
    return (strstr(s, "sports") && !strstr(s, "bieber"));
}

unsigned int sports_or_workout(char* s)
{
    return (strstr(s, "sports") || strstr(s, "working out"));
}

unsigned int ns_theater(char* s)
{
    return (strstr(s, "NS") && strstr(s, "theater"));
}

unsigned int arts_theater_or_dining(char* s)
{
    return (strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining"));
}

```


### Long exercise 2
1. Sort integer scores, with the smallest value
```c
int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int *)score_a;
    int b = *(int *)score_b;
    return a-b;
}
```

2. Sort integer scores, with the largest first
```c
int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int *)score_a;
    int b = *(int *)score_b;
    return b-a;
}
```

3. Sort the rectangles in area order, smallest first
```c
typedef struct
{
    int width;
    int height;
} rectangle;

int compare_areas(const void* a, const void* b)
{
    rectangle* rect_a = (rectangle *)a;
    rectangle* rect_b = (rectangle *)b;

    return ((rect_a->height) * (rect_a->width)) - ((rect_b->height) * (rect_b->width));

}

```
4. Sort a list of names in alphabetical order, case sensitive
```c
int compare_names(const *void a, const *void)
{
    char** str_a = (char **)a;
    char** str_b = (char **)b;

    return strcmp((*str_a), (*str_b));
}

```

5. Sort the rectangles in area order, largest first
```c
int compare_areas_desc(const *void a, const *void b)
{
    return -compare_areas(a, b);
}

```
6. Sort a the names in reverse alphabetical order
```c
int compare_names_desc(const *void a, const *void b)
{
    return -compare_names(a, b);
}
```

### Long Exercise 3
Write a variadic function that calculates the total price of drinks for the *Head First Lounge*
```c

double price(int count, ...)
{
    va_list drinks;

    va_start(drinks, count);

    int i;
    double total = 0;

    for (i = 0; i < count; i++)
    {
        total += cost(va_arg(drinks, enum drink));
    }
    va_end(drinks);

    return total;
}

```

## Chapter 08: Hot-swappable code
### Static and dynamic libraries

#### Bank Vault

#### Gym

#### Exercises

#### Sharpen your pencil 0
![The angle brackets should be double quotes]("https://raw.githubusercontent.com/DaviNakamuraCardoso/c/main/chapter_08/images/ex0.png")

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

## Chapter 09: Breaking boundaries
### Processes and system calls

#### Exercises


##### Code Magnets
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now()
{
    time_t t;
    time (&t);
    return asctime(localtime(&t));
}

/* Master control program utility */
/* Records guard patrol check-ins */
int main(void)
{
    char comment[80];
    char cmd[80];

    fgets(comment, 80, stdin);
    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());
    system(cmd);

    return 0;   
}


```


##### *exec()* function types
| Uses | Character     |
| :------------- | :------------- |
|  List of args       | l       |
| Array/vector of args | v |
| Search in PATH | p |
| Use environment variables | e |

##### Long Exercise
```c
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1)
    {
        if (execlp("ipconfig", "ipconfig", NULL) == -1)
        {
            fprintf(stderr, "Cannot run ifconfig: %s", strerror(errno));
            return 1;
        }
    }
    return 0;
}
```

##### Mixed Messages
Code for the program "coffe":
```c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
char *w = getenv("EXTRA");
if (!w)
w = getenv("FOOD");
if (!w)
w = argv[argc - 1];
char *c = getenv("EXTRA");
if (!c)
c = argv[argc - 1];
printf("%s with %s\n", c, w);
return 0;
}

```

Test program:
```c
#include <string.h>
#include <stdio.h>
#include <errno.h>
int main(int argc, char *argv[]){

    /* ---------- CODE GOES HERE ------------ */
        fprintf(stderr, "Can't create order: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}
```
![Answer]("./ex0.png")

## Chapter 10: It's good to talk
## Interprocess communication

### RSSGOSSIP program
In this chapter I've learned how to open other applications using C;
```python
# Copyright (C) 2011 by D+D Griffiths
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
import requests
import os
import re
import sys
import string
import unicodedata
import getopt
import xmltodict
import pprint

def usage():
    print("Usage:\npython rssgossip.py [-uh] <search-regexp>")

try:
    opts, args = getopt.getopt(sys.argv[1:], "uh", ["urls", "help"])
except getopt.GetoptError as err:
    print(str(err))
    usage()
    sys.exit(2)

include_urls = False
for o, a in opts:
    if o == "-u":
        include_urls = True
    elif o in ("-h", "--help"):
        usage()
        sys.exit()
    else:
        assert False, "unhandled option"

searcher = re.compile(args[0], re.IGNORECASE)
site_re = re.compile(r"http(s)?://rss(feeds)?.(.*).com")

for url in os.environ['RSS_FEED'].split():
    feed = requests.get(url).content
    dom = xmltodict.parse(feed)

    fmt_url = site_re.search(url)
    print(f"\n\n______________ Searching on {fmt_url.group(3).capitalize()} __________________\n\n\n")

    forecasts = []
    for desc in dom['rss']['channel']['item']:
        if match := searcher.search(desc['title']):
            print(f" ==== {desc['title'].upper()} ===\n")
            print(desc['description'])
            if (include_urls):
                print(f"\t{desc['link']}")
            print("\n\n")
    print("__________________________________________________________________\n")
sys.exit(0)

```

### Exercises

#### Sharpen your pencil
```c
int main(int argc, char* argv[])
{
    char* phrase =
}

```

#### Pipes
##### Child process

```c
close(fd[0]);
dup2(fd[1], 1);

```
| #     | Data Stream     |
| :------------- | :------------- |
| 0       | Standard Input       |
| 1 | ~~Standard output~~ Write to pipe |
| 2 | Standard Error |
| 3 | ~~Read end of the pipe~~|
| 4 | Write end to the pipe |


##### Parent process

```c
dup2(fd[0], 0);
close(fd[1]);

```
| #     | Data Stream     |
| :------------- | :------------- |
| 0       | ~~Standard Input~~ Read end of the pipe  |
| 1 | Standard output|
| 2 | Standard Error |
| 3 | Read end of the pipe|
| 4 | ~~Write end to the pipe~~ |

### What's my purpose?
![](./ex.png)

# Chapter 11: There is no place like 127.0.0.1
## Sockets and networking


### Exercises
#### Sharpen your pencil
```c

int main(void)
{

    catch_signal(SIGINT, handle_shutdown);

    listener_d = open_listener_socket();

    /* ___________ Bind _____________ */
    bind_to_port(listener_d, 30000);

    /* ___________ Listen _____________ */
    listener_socket(listener_d, 10);



    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    char buff[255];

    while (1)
    {
        /* ___________ Accept ___________ */
        int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

        if (connect_d == -1)
        {
            error("Can't open secondary socket!");
        }
        if (!fork())
        {
            close(listener_d);

            /* __________ Begin ___________ */
            say(connect_d, "Knock! Knock!\r\n");

            int status = read_in(connect_d, buff, sizeof(buff));

            if (status == -1)
            {
                fprintf(stderr, "Could not listen to response");
                close(connect_d);
            }

            if (strncasecmp(buff, "Who's there?", 12) != 0)
            {
                say(connect_d, "The Internet Knock Knock Protocol requires you to say 'Who's there?'.\nConnection reset\n");
                close(connect_d);
            }

            say(connect_d, "Oscar\r\n");

            int status2 = read_in(connect_d, buff, sizeof(buff));

            if (status2 == -1)
            {
                fprintf(stderr, "Could not listen to response");
                close(connect_d);
            }

            if (strncasecmp(buff, "Oscar who?", 10) != 0)
            {
                say(connect_d, "The Internet Knock Knock Protocol requires you to say 'Oscar who?'. \nConnection reset\n");
                close(connect_d);
            }
            say(connect_d, "Oscar silly question, you get a silly answer.\r\n");

            close(connect_d);

            exit(0);

        }

        close(connect_d);

}
```

#### Long exercise

# Chapter 12: It's a parallel world
## Threads


### Exercises
#### Beer Magnets
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int beers = 2000000;

void* drink_lots(void* a)
{
    int i;
    for (i = 0; i < 100000; i++)
    {
        beers--;
    }

    return NULL;
}

int main(void)
{
    pthread_t threads[20];
    int t;

    printf("%i bottles of beer.\n", beers);

    for (t = 0; t < 20; t++)
    {
        pthread_create(threads[t], NULL, drink_lots, NULL);
    }
    void* result;

    for (t = 0; t < 20; t++)
    {
        pthread_join(threads[t], &result);
    }

    printf("There are now %i beers.\n", beers);

    return 0;
}

```

#### Brain power
The variable is not reduced to zero because multiple threads try to update it at
the same time and end up writing the wrong value;

#### Long exercise
![Version B is correct](./ex0.png)

## Other Resources
* [CS61](https://cs61.seas.harvard.edu/site/2021/)
* [Garbage Collector Project](http://maplant.com/gc.html)
* [Baby GC](http://journal.stuffwithstuff.com/2013/12/08/babys-first-garbage-collector/)


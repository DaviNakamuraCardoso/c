# It's good to talk
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

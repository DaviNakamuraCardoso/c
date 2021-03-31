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
site_re = re.compile(r"http(.*).com")

for url in os.environ['RSS_FEED'].split():
    feed = requests.get(url).content
    dom = xmltodict.parse(feed)

    fmt_url = site_re.search(url).group(0)
    print(f"\n\n______________ Searching on {fmt_url} __________________\n\n\n")
    forecasts = []
    for desc in dom['rss']['channel']['item']:
        if match := searcher.search(desc['title']):
            print(f" ==== {desc['title'].upper()} ===\n")
            print(desc['description'])
            print("\n\n")
    print("__________________________________________________________________\n")
sys.exit(0)

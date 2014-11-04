#!/usr/bin/python
#coding=utf8
import sys
import urllib2

def search(q):
    url = 'http://cn.bing.com/dict/search?q='+urllib2.quote(q)
    response = urllib2.urlopen(url)
    html = response.read()
    flag = 'meta name="description"'
    pos = html.find(flag)
    beg = html.find('"',pos+len(flag)+1)
    end = html.find('"',beg+1)
    content = html[beg+1:end]
    result = set([])
    for e in content.replace(';',' ').replace('；',' ').split()[1:]:
        if e[-1] != '.' and '网络释义' not in e:
            result.add(e)
    print '[{}]'.format(q)
    print '---------------'
    print '\n'.join(result)

search(sys.argv[1])


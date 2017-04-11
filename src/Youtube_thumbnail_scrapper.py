_author_ = 'Justin Kaipada'
#youtube thumbnail scrapper wriiten in python 3.4

from bs4 import BeautifulSoup
import urllib.request
i=1
j=1
while i==1:
    print('Enter the video(youtube) url..only video url..not playlists n all')
    url=input()
    l=len(url)
    if(url[0:29]!='https://www.youtube.com/watch' and url[0:17]!='https://youtu.be/'):
        print("invalid url")
    elif(l>=47):
        print('invalid url')
    else:
        html=urllib.request.urlopen(url)
        i=0
soup=BeautifulSoup(html,'html.parser')
text=soup.prettify()
str2='jpg'
index=text.find(str2)
if(index==-1):
    print('invalid url')
else:
    index=index+3
    beg=index-52
    while j==1:
        turl=text[beg:index]
        if (turl[0]!='h'):
            beg=beg+1
        else:
            print(turl)
            j=0
input()

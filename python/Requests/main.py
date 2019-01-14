import requests

s = requests.Session()
s.headers.update({'referer': my_referer})
html = s.get(url)
print html.content

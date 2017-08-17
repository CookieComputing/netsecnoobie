import requests
import json

web = "http://www.scicademy.org/addUser"
myData = {"fnm":"firstName","lnm":"lastName","grd":"12","shl":"school","eml":"fuckme@fuck.com","pwd":"password1","dte":"08/14/2017","isSum":False,"referrer":"aram"}
myHeaders = { "Host": "www.scicademy.org", "User-Agent": "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:54.0) Gecko/20100101 Firefox/54.0", "Accept": "application/json, text/javascript, */*; q=0.01", "Accept-Language": "en-US,en;q=0.5", "Content-Type": "application/json", "X-Requested-With": "XMLHttpRequest", "Referer": "http://www.scicademy.org/","Content-Length": "156", "Cookie": "_ga=GA1.2.804063011.1502758976; _gid=GA1.2.987408565.1502758976; _gat=1", "Connection": "close"}

#r = requests.post(web,data=json.dumps(myData))
#r = requests.post(web,data=json.dumps(myData),headers=myHeaders)
print(len(str(myData).replace(" ","")) + 1)

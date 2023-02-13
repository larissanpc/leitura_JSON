#Larissa Rafaela Rodrigues Nepomuceno
from urllib.request import urlopen
import json

url = "https://api-simple-flask.herokuapp.com/api/" 
lista =["alzr","bcri","brcr","cpff","cpts","deva","habt","hctr","hsml","irdm","knri","mgff","rbff","rbrf","recr","rect","urpr", "vghf", "vgip", "vslh","xpci","xplg","xpml","xppr"]

for i in range(len(lista)):
  
  response = urlopen(url+lista[i])

  data = json.loads(response.read())

  print(data["nomePregao"])
  print('('+data["fundo"]+')')
  print(data["dividendYield"])
  print(data["valorAtual"])
  print(data["valorPatrimonioPCota"])

  resp = 'AGUARDAR'
  if(data["valorAtual"]<data["valorPatrimonioPCota"]):
    resp = 'COMPRAR'
  print(resp)

  f = open("fii.csv","a")
  f.write(data["nomePregao"]+' ('+data["fundo"]+')'+";"+repr(data["dividendYield"])+';'+repr(data["valorAtual"])+';'+repr(data["valorPatrimonioPCota"])+';'+resp+'\n')


  f.close()

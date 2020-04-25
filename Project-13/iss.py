import requests
from gpiozero import LEDBarGraph
from time import sleep

leds = LEDBarGraph(17, 18, 27, 22, 23, 24, 10, 25, 9, 11)

url = "http://api.open-notify.org/astros.json"

while True:
    r = requests.get(url)
    data = r.json()
    people = data['number']
    print(people)
    leds.value = people/10
    sleep(60)
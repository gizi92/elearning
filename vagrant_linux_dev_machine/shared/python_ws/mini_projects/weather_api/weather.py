from urllib import response
import requests
from pprint import pprint

# https://openweathermap.org/api
API_KEY = "your_api_key"
BASE_URL = "http://api.openweathermap.org/data/2.5/weather"

city = input("Enter a city name: ")
units = "metric"
request_url = f"{BASE_URL}?appid={API_KEY}&q={city}&units={units}"
response = requests.get(request_url)

if response.status_code == 200:
    data = response.json()
    weather = data["weather"][0]["description"]
    pprint(f"Weather: {weather}")
    temperature = data["main"]["temp"]
    pprint(f"Temperature: {temperature} [°C]")
else:
    print(f"HTTP error: {response.status_code}")
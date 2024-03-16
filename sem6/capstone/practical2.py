# Alarm clock
#  Url shorter
#  Weather app

#  Alarm Clock 
from datetime import datetime
import time 

# url shortner
import pyshorteners

# Weather app
import requests
from bs4 import BeautifulSoup

def set_Alarm():
    print("Enter the time for the alarm in 24-hour format (HH:MM):")
    alarm_time = input(">> ")
    
    alarm_hr,alarm_min = map(int, alarm_time.split(":"))
    
    current_time_hour,current_time_min,current_time_sec = map(int ,((datetime.now()).strftime("%H:%M:%S").split(":")));
    
    time_diff_hr = ((alarm_hr - current_time_hour) * 3600) + ((alarm_min- current_time_min) * 60) - current_time_sec
    if(time_diff_hr<0):
        print("Invalid")
        exit()
        
    print("wait for : ",time_diff_hr ,"s")
    time.sleep(time_diff_hr)
    print("ALARM !!!")
# set_Alarm();

def weather_App():
    city = input("Enter the city name: ")
    city_no_space = city.replace(" ", "")
    
    r = requests.get(f'https://www.weather-forecast.com/locations/{city_no_space}/forecasts/latest')
 
    # check status code for response received
    # success code - 200
    # print(r)
    
    # print content of request
    # print(r.content)
    soup = BeautifulSoup(r.content, 'html.parser')
    # print(soup)
    temperature_span = soup.find('span', class_='temp')
    place = soup.find('div', class_='main-title__issued show-for-medium-up')

    if(temperature_span and place):
        temperature_span = temperature_span.text.strip();
        place = place.text.strip();
    else : 
        print('Error')
        exit()
    
    print(f"temperature: {temperature_span}° C")
    print (f'Place is: {place.split("forecast")[0]}')
    print ( f'last updated : {(place.split("issued:")[1]).split("| Update")[0]}')

# weather_App();

def url_shortener():
    long_url = input("Enter your long url: ")
    s = pyshorteners.Shortener()
    short_url = s.tinyurl.short(long_url)
    print (f"Your short Url is: {short_url}")

url_shortener()
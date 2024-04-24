# Password Strength Checker
# Youtube video downloader
# Object detector

import re
import os
import sys
import requests
from pytube import YouTube

def password_strength(password):
    if len(password) < 8:
        return 'Password must be at least 8 characters long'
    elif re.search(r'[a-z]', password) is None:
        return 'Password must contain at least one lowercase letter'
    elif re.search(r'[A-Z]', password) is None:
        return 'Password must contain at least one uppercase letter'
    elif re.search(r'[0-9]', password) is None:
        return 'Password must contain at least one digit'
    elif re.search(r'[^a-zA-Z0-9]', password) is None:
        return 'Password must contain at least one special character'
    else:
        return 'Password is strong'
    
def download_youtube_video(url):
    try:
        yt = YouTube(url)
        video = yt.streams.filter(progressive=True, file_extension='mp4').first()
        video.download(output_path='E:\yt video download',filename=f'{video.default_filename}.mp4')
        return 'Video downloaded successfully'
    except Exception as e:
        return f'Error downloading video: {e}'
    
    
def object_detector(image_path):
    try:
        os.system(f'python object_detection.py --image {image_path}')
    except Exception as e:
        return f'Error detecting objects: {e}'
    
if __name__ == '__main__':
    print('1. Password Strength Checker')
    print('2. Youtube Video Downloader')
    print('3. Object Detector')
    choice = int(input('Enter your choice: '))
    
    if choice == 1:
        password = input('Enter password: ')
        print(password_strength(password))
    elif choice == 2:
        url = input('Enter youtube video url: ')
        print(download_youtube_video(url))
    elif choice == 3:
        image_path = input('Enter path to image: ')
        print(object_detector(image_path))
    else:
        print('Invalid choice')
        sys.exit(1)

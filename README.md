# G930BatteryReader
This is a simple program written in C and compiled using Code::Blocks 16.01 and GCC. 

Its purpose is reading the battery value from the Logitech G930 software and writing the battey value to a txt file.

It was coded to support a modified Rainmeter battery skin, download link below. To make the rainmeter skin work you will have to edit the line
```
Url=file://C:\UOW\batteryLevel.txt
```
And change it to the path of your batteryLevel.txt file.

It has only been tested on Windows 7 x64 using version 1.00.364 of the Logitech G930 x64 software: the download link is included below.

This will NOT work with the newer "Logitech Gaming Software".

I personally have it scheduled to start at logon on the windows task scheduler through "Quiet" (to make it invisible, see download link below). To use this program with Quiet you can use this batch script (simply copy its code in a txt file in the same directory as the exe and rename the extension from txt to bat:
```
timeout /t 60 /nobreak
Quiet.exe "G930BatteryReader.exe"
```
The batch script above delays its start by 60 seconds because if the exe starts before the the Logitech G930 software it will automatically close itself.

You are free to use this program and its code however you want.

## Downloads
Logitech G930 v1.00.364: http://download01.logitech.com/web/ftp/pub/gaming/g930/g930_100364b_x64.exe

Rainmeter skin: https://aww.moe/hxsobb.zip

Credits for the original Rainmeter skin go to **eight-wonder** and **shailendra** on Deviantart.

Quiet: http://www.joeware.net/downloads/dl.php


## FAQ
How was this done?
>The short version: using Cheat Engine, various Windows C/C++ APIs, fairly standard C code and by reading a lot of Microsoft documentation and stackoverflow answers.

Why was this done?
>Because I wanted a rainmeter skin which displayed my G930 headset battery, so I created one.

Why didn't you code it for the newer Logitech Gaming Software instead of the outdated Logitech G930 software?
>Because I personally find the LGS quite bloated, also it had an issue which caused the headset to restart every ~15 minutes, so I use the older version.

##Screenshots

![alt tag](https://aww.moe/0uh8m9.png)

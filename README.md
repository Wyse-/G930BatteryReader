# G930BatteryReader

## Screenshots

![alt tag](https://aww.moe/0uh8m9.png)
Note: the command line window is only used for demonstration / debugging purposes, following the how-to steps it will effectively be invisible thanks to a program called Quiet.

Alternative skin:
![alt tag](https://a.doko.moe/odtsxc.PNG)
If you are looking for something that doesn't rely on Rainmeter see https://github.com/Wyse-/G930BatteryReader-CLIBar
## How-to
- Make sure you have the Logitech G930 v1.00.364 x64 software installed and set to autostart. If you don't, download link below. Keep in mind this is different from the Logitech Gaming Software: if you have that installed uninstall it and install the one I provided below.
- Download the latest executable from the releases page (https://github.com/Wyse-/G930BatteryReader/releases)
- Place the exe wherever you want.
- Download Quiet.exe, link below.
- Place Quiet.exe in the same directory as G930BatteryReader.exe.
- Create a new txt file, and paste the following in it:
```
timeout /t 60 /nobreak
Quiet.exe "G930BatteryReader.exe"
```
- Optionally adjust the timeout value (it's in seconds) based on your computer / hard drive speed. The point is that G930BatteryReader.exe has to start after the Logitech G930 software is already started, otherwise it will just close.
- Rename the text file extension from .txt to .bat.
- Add the bat file as an autostart program via the task scheduler or the registry (if you don't know how to just google it)
- Download the Rainmeter skin, link below.
- Extract the folder in the zip to `C:\Users\YourUsername\Documents\Rainmeter\Skins`.
- Open battery.ini with notepad and look for the line `Url=file://C:\UOW\batteryLevel.txt`, then change the file path to the path where you extracted G930BatteryReader.exe. The batteryLevel.txt file will always be created by the program in its same directory.
- Load the skin through Rainmeter.
- Done!

## Downloads
Logitech G930 v1.00.364: http://download01.logitech.com/web/ftp/pub/gaming/g930/g930_100364b_x64.exe

Rainmeter skin: https://aww.moe/hxsobb.zip

Alternative skin: https://a.doko.moe/sjswbj.zip

Credits for the original Rainmeter skin go to **eight-wonder** and **shailendra** on Deviantart.

Quiet: http://www.joeware.net/freetools/tools/quiet/index.htm

## Description
This is a simple program written in C and compiled using Code::Blocks 16.01 and GCC. 

Its purpose is reading the battery value from the Logitech G930 software and writing the battey value to a txt file. It updates the value every 5 seconds.

It was coded to support a modified Rainmeter battery skin, download link above. To make the rainmeter skin work you will have to edit the line
```
Url=file://C:\UOW\batteryLevel.txt
```
And change it to the path of your batteryLevel.txt file.

It has only been tested on Windows 7 x64 using version 1.00.364 of the Logitech G930 x64 software: the download link is included above.

This will NOT work with the newer "Logitech Gaming Software".

I personally have it scheduled to start at logon on the windows task scheduler through "Quiet" (to make it invisible, see download link above). To use this program with Quiet you can use this batch script (simply copy its code in a txt file in the same directory as the exe and rename the extension from txt to bat:
```
timeout /t 60 /nobreak
Quiet.exe "G930BatteryReader.exe"
```
The batch script above delays its start by 60 seconds because if the exe starts before the the Logitech G930 software it will automatically close itself.

You are free to use this program and its code however you want.

## FAQ
How was this done?
>The short version: using Cheat Engine, various Windows C/C++ APIs, fairly standard C code and by reading a lot of Microsoft documentation and stackoverflow answers.

Why was this done?
>Because I wanted a rainmeter skin which displayed my G930 headset battery, so I created one.

Why didn't you code it for the newer Logitech Gaming Software instead of the outdated Logitech G930 software?
>Because I personally find the LGS quite bloated, also it had an issue which caused the headset to restart every ~15 minutes, so I use the older version. If you are looking for something compatible with the LGS check out Snipeon's LGSBatteryReader:
https://github.com/Snipeon/LGSbatt-rainmeter

Are the program and Rainmeter skin resource intensive?
>Nope. G930BatteryReader.exe uses about 300 Kb of RAM and no CPU usage that I can speak of, as for the skin I'm not really sure how to tell how much it uses specifically, but I'm sure it's a negligible amount.

Why didn't you code it in x programming language?
>I'm a beginner, I've only ever used C so that's what I used.

How is the battery value stored in memory by the Logitech G930 software?
>It's stored in minutes remaining. For example, when the battery is full and it says "10 hours remaining", the battery value will be 601 (601 / 60 = 10.01). If you are looking for an exact value the best thing to do is wait for the battery to be low enough that the time remaining is displayed in minutes (e.g. 14 minutes remaining would be stored in memory as exactly 14).

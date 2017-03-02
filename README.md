# imshow - plot graph

The source code is based on Visual Studio Project 2013 Community with  Ceemple addon of OpenCV

# Windows : prebuilt binary

Search for imshow.zip. It contains the executable along with dll files.

# Usage

It uses default "plot.txt" file which have set of commands with paramenter which are interpreted.

Other files can be imported by commandline arguement

Basic set of commands are included in plot.txt

# plot.txt

200 200
color 255 255 255
radius 5
thick 1
dot 20 20
dot 60 40
dot 80 100
line 20 20 60 40
line 60 40 80 100
line 20 20 80 100
wait 1000
clear 0 0 0
dot 20 20
dot 60 40
dot 80 100
line 20 20 60 40
line 60 40 80 100
line 20 20 80 100
wait 1000


Here first line denotes size of image
color in RGB format
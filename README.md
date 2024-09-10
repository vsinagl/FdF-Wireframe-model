# FDF 🗺 by vsinagl 

### Wireframe Model Renderer in C

![FDF by vsinagl](/img/fdf.gif)

Project from 42 Prague. Graphical renderer that used minilibx and X11 server (graphical library that provide API for communication with X11 server)

## FDF Maps

![FDF by vsinagl](/img/pyramide.png)

Inputs for visualization
- basic table with numbers and hexadacimal codes for colors
- look at maps at `maps/` folder to see how .fdf filetypes looks like

## Projection

Program provide **izometric**, **parallel** and **cavalier** projection
- izometric and cavalier projection is rotated by default in 45 degrees angle

## Downloading and installation 

### Linux

1. clone the repository
2. for minilibx you will need to download some aditional dev libraries 
``` bash
sudo apt-get update && sudo apt-get install -y xorg libbsd-dev libx11-dev libxext-dev zlib1g-dev
```
3. compile the project with make
```bash
make
```
4. run project, you can run the executable with path to map as an argument
```bash
./fdf maps/mars.fdf
```
or use run.sh script to view available maps
``` bash
bash run.sh
```

### Docker container
 - 😿 to be done...  

## minilibx

minilibx graphical library is in mlx_linux folder. You can find here source codes and makefiles for compilation.
- 🚨 if you have problem with compiling project or X11 server, you can use tests for minilibx in `mlx_linux/test` folder

## Navigation

you can use following keys for navigation:
- `q, e` for rotating
- `x, z` for zooming out
- `w, s, a, d` for moving the picture
- `c` for changing perspective
- `ESC` for exiting program. Or u can press on top righ corner button 😄

# Like it ? give it a ⭐


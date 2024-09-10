docker run -it \
    --rm \
    --env="DISPLAY=$DISPLAY" \
    --env="XAUTHORITY=$XAUTHORITY" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --name=fdf-container \
    fdf:latest

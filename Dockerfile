
FROM silkeh/clang:latest

WORKDIR /fdf

COPY . /fdf

# installing dependencies
RUN apt-get update && apt-get install -y \
    make \
    gcc \
    xorg \ 
    libbsd-dev \
    libx11-dev \
    libxext-dev \
    zlib1g-dev \ 
    && rm -rf /var/lib/apt/lists/*

RUN make

RUN chmod +x fdf

ENTRYPOINT ["/bin/bash", "/fdf/run.sh"]
#ENTRYPOINT ["/fdf/fdf"]
#CMD ["/bin/bash"]


#zlib1g-dev is zlib compresion library that i used for the custom png. menu i made

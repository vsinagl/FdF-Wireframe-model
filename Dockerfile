# Use Clang as the base image
FROM silkeh/clang:latest

# Set the working directory in the container
WORKDIR /fdf

# Copy the current directory contents into the container
COPY . /fdf

# Install make (if not already present in the Clang image)
RUN apt-get update && apt-get install -y \
    make \
    libx11-dev \
    libxext-dev \
    zlib1g-dev \ 
    && rm -rf /var/lib/apt/lists/*

# Build your project using make
RUN make

# Ensure the executable has the right permissions
RUN chmod +x fdf

# Set the entrypoint to a shell script that we'll create
#ENTRYPOINT ["/bin/bash", "/fdf/run.sh"]
ENTRYPOINT ["/fdf/fdf"]


#zlib1g-dev is zlib compresion library that i used for the custom png. menu i made

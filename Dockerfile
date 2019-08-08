FROM ubuntu:bionic

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libsdl2-dev

COPY . /src
WORKDIR /src/build
RUN cmake .. && make

CMD ./sdl-rendering
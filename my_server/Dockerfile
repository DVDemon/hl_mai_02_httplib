FROM ubuntu:latest
ENV TZ=Europe/Moscow
RUN apt-get clean && apt-get update -y 
RUN DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC apt-get -y install tzdata git cmake gcc g++ libssl-dev && apt-get clean
RUN git clone https://github.com/yhirose/cpp-httplib
RUN cd cpp-httplib && mkdir build && cd build && cmake  .. && make && make install && cd .. && cd ..
RUN git clone https://github.com/DVDemon/hl_mai_02_httplib.git
RUN cd hl_mai_02_httplib && mkdir build && cd build && cmake  .. && make
CMD [ "hl_mai_02_httplib/build/server" ]
FROM ubuntu:bionic

RUN apt-get update && \
    apt-get -y full-upgrade

RUN apt-get -y install --no-install-recommends \ 
    perl \
    g++ \
    make \
    verilator

# TODO: remove
RUN apt list verilator
RUN dpkg -L verilator

ADD . build/
WORKDIR build/

CMD ["bash", "-c", "make run-sim"]

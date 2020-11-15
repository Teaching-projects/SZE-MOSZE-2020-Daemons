FROM ubuntu:20.04

ENV TZ=Europe/Budapest
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get install --no-install-recommends -y \
  make \
   doxygen \
   && apt-get install -y git \
   g++ \
   g++-10 \
   valgrind \
   cppcheck \
   libgtest-dev \
   cmake \
   graphviz \
&& rm -rf /var/lib/apt/lists/*

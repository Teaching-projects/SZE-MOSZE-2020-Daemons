FROM ubuntu:20.04

RUN apt-get update && apt-get install --no-install-recommends -y \
  make \
   doxygen \
   g++ \
   valgrind \
   cppcheck \
   libgtest-dev \
   cmake \
   graphviz \
&& rm -rf /var/lib/apt/lists/*

FROM ubuntu:20.04

RUN apt-get update && apt-get install --no-install-recommends -y \
  make \
   doxygen \
   g++ \
   g++-10 \
   valgrind \
   cppcheck \
   libgtest-dev \
   cmake \
   graphviz \
&& rm -rf /var/lib/apt/lists/*

FROM gjyoung1974/cmake:latest

ADD . /src
WORKDIR /src

#no run test for now since there is no env vars put in
RUN cmake /src 
RUN cmake --build /src 

CMD ["/bin/bash -c", "tail -f /dev/null"]

FROM ubuntu:18.04


RUN ["apt-get", "update"]
RUN ["apt-get", "install", "-y", "wget"]
RUN ["apt-get", "install", "-y", "zsh"]
RUN ["apt-get", "install", "-y", "gcc"]
RUN ["apt-get", "install", "-y", "man"]
RUN wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | zsh || true

WORKDIR /workspace
COPY . /workspace

CMD ["zsh"]

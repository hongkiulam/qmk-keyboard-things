#!/bin/bash

docker build -f ./Dockerfile.flash . -t hkqmk-flash
docker run --rm \
  --privileged -v /dev:/dev \
  -it \
  hkqmk-flash \
  qmk compile -kb $1 -km $2:flash
#!/bin/bash

docker build . -t hkqmk
docker run --rm \
  -it \
  -v $(pwd)/.build:/home/qmk/qmk_firmware/.build \
  hkqmk \
  qmk compile -kb $1 -km $2 
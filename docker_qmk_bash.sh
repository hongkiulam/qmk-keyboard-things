#!/bin/bash

docker build . -t hkqmk
docker run --rm \
  -it \
  -v $(pwd)/keyboards:/home/qmk/qmk_firmware/keyboards \
  hkqmk \
  bash
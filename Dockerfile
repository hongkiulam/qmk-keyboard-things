FROM qmkfm/qmk_cli

# Add unprivileged user before setup (no longer needed it seems, keeping for reference)
# RUN groupadd --gid 1000 qmk \
#   && useradd --uid 1000 --gid qmk --shell /bin/bash --create-home qmk
# USER qmk

# clones necessary qmk files from repo
RUN qmk setup -y -H /home/qmk/qmk_firmware
WORKDIR /home/qmk/qmk_firmware
# setup build environment
ENV QMK_FIRMWARE_DIR=/home/qmk/qmk_firmware
RUN apt-get update && apt-get install sudo -y
RUN . ./util/install/debian.sh && _qmk_install

COPY ./keyboards ./keyboards

CMD ["bash"]
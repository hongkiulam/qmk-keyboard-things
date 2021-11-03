FROM qmkfm/qmk_cli

# Add unprivileged user before setup

RUN groupadd --gid 1000 qmk \
  && useradd --uid 1000 --gid qmk --shell /bin/bash --create-home qmk
USER qmk
RUN qmk setup -y -H /home/qmk/qmk_firmware

WORKDIR /home/qmk/qmk_firmware
COPY ./keyboards ./keyboards

CMD ["bash"]
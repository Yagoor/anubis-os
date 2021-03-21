ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/base:${VARIANT}

# Initial update
RUN apt-get update \
    && export DEBIAN_FRONTEND=noninteractive
    
# Basic build files
RUN apt-get -y install build-essential cmake cppcheck \
        valgrind libcmocka-dev vim uncrustify libxml2-utils \
        doxygen graphviz

# ESP32 toolchain
RUN cd tmp \
    && wget --quiet https://github.com/espressif/crosstool-NG/releases/download/esp-2020r3/xtensa-esp32-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz \
    && tar -xf xtensa-esp32-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz \
    && cp -r xtensa-esp32-elf/* /usr/ \
    && rm -rf * \
    && cd -
    
# Clean up
RUN apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*
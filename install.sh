#!/bin/bash

echo "Setting up submodules..."
git submodule update --init --recursive

ID_LIKE=$(grep 'ID_LIKE=' /etc/os-release | sed 's/ID_LIKE=//; s/"//g' 2>/dev/null)
echo "Detected ID_LIKE: $ID_LIKE"

# Define the function for checking and installing packages
check_and_install_package() {
    PACKAGE_MANAGER=$1
    REQUIRED_PKG=$2

    case $PACKAGE_MANAGER in
        "apt")
            PKG_OK=$(dpkg-query -W --showformat='${Status}\n' "$REQUIRED_PKG" | grep "install ok installed")
            INSTALL_CMD="sudo apt-get --yes install $REQUIRED_PKG"
            ;;
        "brew")
            PKG_OK=$(brew list "$REQUIRED_PKG" &>/dev/null && echo "install ok installed")
            INSTALL_CMD="brew install $REQUIRED_PKG"
            ;;
        "dnf")
            PKG_OK=$(dnf list installed "$REQUIRED_PKG" &>/dev/null && echo "install ok installed")
            INSTALL_CMD="sudo dnf install -y $REQUIRED_PKG"
            ;;
        *)
            echo "Unsupported package manager: $PACKAGE_MANAGER"
            exit 1
            ;;
    esac

    echo "Checking for $REQUIRED_PKG: $PKG_OK"
    if [ "" = "$PKG_OK" ]; then
        echo "No $REQUIRED_PKG. Setting up $REQUIRED_PKG."
        eval "$INSTALL_CMD"
    fi
}

echo "Checking for Sfml Dependencies..."
if [ "$(uname)" == "Darwin" ]; then
    for pkg in libdv openal-soft libvorbis libsndfile libxcursor libxrandr libxinerama libxi mesa-glu freetype; do
        check_and_install_package "brew" "$pkg"
    done
elif [[ "$ID_LIKE" == *"debian"* ]]; then
    for pkg in libudev-dev libopenal-dev libvorbis-dev libflac-dev libxcursor-dev libxrandr-dev libxinerama-dev libxi-dev libgl1-mesa-dev libfreetype-dev; do
        check_and_install_package "apt" "$pkg"
    done
elif [[ "$ID_LIKE" == *"fedora"* ]]; then
    for pkg in systemd-devel openal-soft-devel libvorbis-devel flac-devel libXcursor-devel libXrandr-devel libXinerama-devel libXi-devel libGL-devel freetype-devel; do
        check_and_install_package "dnf" "$pkg"
    done
fi

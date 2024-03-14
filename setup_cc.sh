BUILDROOT_PATH=$(find ~/ -type f -path '*/buildroot/.config' -exec dirname {} \; 2>/dev/null | head -n 1)
echo "Searching the buildroot path in home directory"
export PATH=$PATH:$BUILDROOT_PATH/output/host/usr/bin/
echo "Buildroot found! PATH is set"

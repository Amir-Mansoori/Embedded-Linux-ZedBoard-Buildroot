BUILDROOT_PATH=$(find ~/ -type f -path '*/buildroot/.config' -exec dirname {} \; 2>/dev/null | head -n 1)
UBOOT_PATH="${BUILDROOT_PATH}/output/build/uboot-custom"
LINUX_PATH="${BUILDROOT_PATH}/output/build/linux-custom"

touch "${UBOOT_PATH}/.files-list.before" "${UBOOT_PATH}/.files-list-staging.before" "${UBOOT_PATH}/.files-list-images.before" "${UBOOT_PATH}/.files-list-host.before" "${LINUX_PATH}/.files-list.before" "${LINUX_PATH}/.files-list-staging.before" "${LINUX_PATH}/.files-list-images.before" "${LINUX_PATH}/.files-list-host.before"


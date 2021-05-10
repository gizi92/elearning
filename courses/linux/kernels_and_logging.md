# 1. The Linux Boot Loader
## Linux Boot Process
1. Firmware stage
    - Executes code in the BIOS for legacy systems
    - Executes code in the UEFI firmware for new computers
    - Starts boot loader
2. Bootloader stage
    - Firmware executes the boot loader (grub2) code on the drive
    - Bootloader reads its configuration file:
        - BIOS: /boot/grub2/grub.cfg
        - UEFI: /boot/efi/EFI/redhat/grub.efi
    - Executes the kernel
3. Kernel stage
    - Kernel loads the ramdisk into ram
    - Kernel loads device drivers and config files from ramdisk
    - Kernel unmount ramdisk and mounts root filesystem
    - Starts the initialization stage
4. Initialization stage
    - Kernel starts the grandfather process (systemd)
    - Systemd starts system services
    - Systemd starts login shells and GUI

### Systemd Targets
- Target is a specific configuration
- Default target is graphical.target
- Systems can be booted into different targets

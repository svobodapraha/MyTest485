enable_uart=1

serial0 -> ttyS0
serial1 -> ttyAMA0

$ sudo systemctl stop serial-getty@ttyS0.service
$ sudo systemctl disable serial-getty@ttyS0.service

$ sudo nano /boot/cmdline.txt

dwc_otg.lpm_enable=0
console=serial0,115200
console=tty1 root=/dev/mmcblk0p2 
rootfstype=ext4 elevator=deadline 
fsck.repair=yes root wait

dtoverlay=pi3-disable-bt
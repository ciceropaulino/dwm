#!/bin/sh

#set keyboard layout
setxkbmap -layout us -variant intl

#start picom
picom --experimental-backends

#set background
zsh /home/comrade/fehbg.sh

#start slstatus
slstatus

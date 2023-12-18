#!/usr/bin/bash
bladeRF-cli -i <<EOF
set frequency rx 1575420000
set samplerate rx 2048000
set bandwidth rx 50000000
rx config file=rx_fb50M.sc16q11 format=bin n=144000000
rx start;rx wait
quit
EOF

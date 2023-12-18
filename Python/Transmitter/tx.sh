#!/usr/bin/bash
bladeRF-cli -i <<EOF
set frequency tx   1575420000
set Bandwidth tx   10000000
set samplerate tx  4000000
set gain tx 10
tx config file=fc70M_fs4M_wo_fractional_delay.sc16q11 format=bin 
tx config repeat=1 delay=1
tx start;tx wait
quit
EOF

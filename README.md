# Project done under Dr.GVV Sharma Assoc Prof IITH

### Implemented the navic L1 receiver in a real time using SDR

### Requirements: 

#### Hardware:
1.USRP SDR

2.bladerf SDR

3.PC with 64 bit Linux os

#### software:

1.uhd(USRP application)


### specifications:

Receiver sampling frequency is at 2.048 Mhz


## Installations:

Install the configurations for bladerf and usrp from the https://github.com/dudekulauseni123/Navic-project/blob/main/Navic/installations.txt

## Transmiter

For generating the samples get the below folder 

```
 svn co https://github.com/dudekulauseni123/L1/tree/main/Python/Transmitter
```

```
 python3 l1_tx_sim.py 
```

This command will generate bin file that contain the IQ samples of 36 sec with 16 bit  i.e in bin file 1st 16 bits is I and second 16 bits is Q and this flow will continous and this file will be for sdr implementation

## Receiver

In order to run the navic reciver get the folder below

```
 svn co https://github.com/dudekulauseni123/L1/tree/main/Python/Receiver
```

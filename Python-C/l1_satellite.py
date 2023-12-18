import numpy as np
from fractions import Fraction
import math
import scipy.constants as sciconst
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
from mpl_toolkits.mplot3d import Axes3D
from scipy.fftpack import fft
import scipy.signal
from sk_dsp_comm import fec_conv as fec     #pip/pip3 install scikit-dsp-comm
from numpy_ringbuffer import RingBuffer
from random import *
from ldpc import bp_decoder
import struct
import csv
import l1functions as l1

def transform_complex(line):
    return line.replace(b' ', b'').replace(b'+-', b'-').replace(b'i', b'j')
    
dataCodeLength = 10230
pilotCodeLength = 10230
pilotOverlayCodeLength = 1800
codeFreqBasis = 1.023e6

bufsize_power_estimation = 10  # number of samples to be considred for estimating SNR
cn0_min = 25 # Min  Squared Signal-to-Noise Variance estimator in db-Hz
detector_threshold = 0.85 # Phase lock detector threshold
lock_fail_counter_threshold = 25 #Maximum value for the lock fail counter
lock_counter_threshold = 20



#sampleRate = 10*codeFreqBasis
sampleRate = 3000000
samplePeriod = 1/sampleRate
symbolRate = 100
#satId is the satellite ID for multiple satellites to track
satId = np.arange(1,65)
#satId = np.array([25,41])
#satId = np.array([27])
numChannel = len(satId)

#numChannel = 2

#frequrency shift to be applied to the signal
#fShift = np.array([489, 1299, 3796, 4888])
#fShift = np.array([3801,3921])
#fShift = np.array([0,0,0,0])
#channelpfo = l1.PhaseFrequencyOffset(sampleRate)
#sigDelay is the delay in samples in channels
#sigDelay = np.array([300.34, 587.21, 488.32, 531.78])
#sigDelay = np.array([425.89, 312.88])
#dynamicDelayRange = 50
#staticDelay = np.round(sigDelay - dynamicDelayRange)
#channelstatd = l1.IntegerDelay(staticDelay)
#channelvard = l1.FractionalDelay(1, 65535)

PLLIntegrationTime = 10e-3
PLLNoiseBandwidth = 18 # In Hz
#PLLNoiseBandwidth = 18 # In Hz
#FLLNoiseBandwidth = 4 # In Hz
FLLNoiseBandwidth = 2 # In Hz
DLLNoiseBandwidth = 1  # In Hz


#simulation duration, steps at which values are recorded(here for every 10ms)
simDuration = 18

#timeStep = 1
timeStep = PLLIntegrationTime
numSteps = round(simDuration/timeStep)
samplePerStep = int(timeStep/samplePeriod)


codeTable_data = l1.genNavicCaTable_Data(sampleRate, dataCodeLength,codeFreqBasis, satId)
codeTableSampCnt_data = len(codeTable_data)


codeTable_pilot = l1.genNavicCaTable_Pilot(sampleRate, pilotCodeLength,codeFreqBasis,  satId)
codeTableSampCnt_pilot = len(codeTable_pilot)

datagen = l1.NavicDataGen(symbolRate, sampleRate, numChannel)
navic_raw_data = datagen.GetDataStream()
pilotOverlayCodegen = l1.PilotOverlayBitGen(satId, pilotOverlayCodeLength, symbolRate, sampleRate)
modulator = l1.NavicL5sModulator(sampleRate)
i=0
waveform = []
istep = 0 

#in order to convert from bin to csv file
def chunked_read( fobj, chunk_bytes = 4*1024 ):
    while True:
        data = fobj.read(chunk_bytes)
        if( not data ):
            break
        else:
            yield data

rx_iq_array=[]

def bin2csv( binfile= None, csvfile= None, chunk_bytes = 4*1024 ):
    with open(binfile, 'rb') as b:
        count = 0
        c=0
        for data in chunked_read(b, chunk_bytes = chunk_bytes):
            count += len(data)
            for i in range(0, len(data), 4):
                sig_i, = struct.unpack('<h', data[i:i+2])
                sig_q, = struct.unpack('<h', data[i+2:i+4])
                sig_i = sig_i/2048.0
                sig_q = sig_q/2048.0
                rx_iq_array.append(1*sig_i+1j*sig_q)
                    #csvwriter.writerow( [sig_i, sig_q] )
            #print(count)
            #print(c)
    print( "Processed", str(count//2//2), "samples." )


bin2csv("rx_3samplerate_1.25bwd.sc16q11", "rxwave.csv",chunk_bytes=4096)

rx_iq_array=np.array(rx_iq_array)


#Plot power spectral density
plt.psd(rx_iq_array[0:30000], Fs = sampleRate )
plt.show()

satVis = 0
vis_list = []
for istep in range(numSteps):
    
    waveform = rx_iq_array[istep*samplePerStep:(istep+1)*samplePerStep] 
    
    # Perform acquisition once from cold-start
    if satVis==0:

        # Acqusition doppler search space
            fMin = -5000
            fMax = 5000
            #The FLL discriminator has a bandwidth of +- 50 , for 10 ms integration duration
            #Hence, to avoid border cases of +- 50, fStep is taken as 80 so that we can have
            # an error of +- 40
            fStep = 80
            fSearch = np.arange(fMin, fMax + fStep , fStep)

            tracker = []
            
        
            
        # Perform acquisition for each satellite
            for prnId in range(numChannel):
                status, codePhase, doppler = l1.navic_pcps_acquisition(
                                                                waveform, 
                                            codeTable_pilot[np.arange(0, samplePerStep)%codeTableSampCnt_pilot, prnId],
                                            sampleRate ,fSearch, relative_peak=False
                                        )   
                delaySamp = codePhase
                codePhase = (codePhase % codeTableSampCnt_data)/(sampleRate/codeFreqBasis)
              
                # If a satellite is visible, initialize tracking loop
                if(status == True):
                    
                    print(f"Acquisition results  for PRN ID {satId[prnId]}\n Status:{status} Doppler:{doppler} Delay/Code-Phase:{delaySamp}/{codePhase}")
                    satVis += 1 
                    vis_list.append(int(satId[prnId])) # List of visible satellites
                    tracker.append(l1.NavicTracker(satId[prnId]))
                    tracker[-1].SampleRate = sampleRate
                    tracker[-1].CenterFrequency = 0
                    tracker[-1].PLLNoiseBandwidth = PLLNoiseBandwidth
                    tracker[-1].FLLNoiseBandwidth = FLLNoiseBandwidth
                    tracker[-1].DLLNoiseBandwidth = DLLNoiseBandwidth
                    tracker[-1].PLLIntegrationTime = round(PLLIntegrationTime*1e3)
                    tracker[-1].PRNID = satId[prnId]
                    tracker[-1].InitialDopplerShift = doppler
                    tracker[-1].InitialCodePhaseOffset = codePhase
                    tracker[-1].setupImpl(dataCodeLength, bufsize_power_estimation, cn0_min, detector_threshold, lock_fail_counter_threshold)
                    tracker[-1].resetImpl()
      
            #trackDataShape = (numSteps*round(PLLIntegrationTime*1e3), satVis)
            trackDataShape = (round(numSteps), satVis)
            y_pilot = np.empty(trackDataShape, dtype=np.complex_)
            y_data = np.empty(trackDataShape, dtype=np.complex_)
            fqyerr = np.empty(trackDataShape)
            fqynco = np.empty(trackDataShape)
            pherr = np.empty(trackDataShape)
            phnco = np.empty(trackDataShape)
            delayerr = np.empty(trackDataShape)
            delaynco = np.empty(trackDataShape)
            cn0_cap = np.empty(trackDataShape)
            pli = np.empty(trackDataShape)
            lock_fail_counter = np.empty(trackDataShape)
            fc = np.empty(trackDataShape)
            coarse_delay = np.empty(trackDataShape)
            fine_delay = np.empty(trackDataShape)
           # input_phase = np.empty(trackDataShape)

	

    # Perform tracking for visible satellite
    #print(satVis)
    for i in range(satVis):
            y_pilot[istep, i], y_data[istep,i],fqyerr[istep, i], fqynco[istep, i], pherr[istep, i], phnco[istep, i], delayerr[istep, i], delaynco[istep, i], cn0_cap[istep,i], pli[istep,i], lock_fail_counter [istep,i],fc[istep,i],coarse_delay[istep,i], fine_delay[istep,i] = tracker[i].stepImpl(waveform)

#print(len(y_pilot))

k = len(y_data)    
print(k)


#Get the pilot overlay code for all visible satellites
vis_list1 = np.array(vis_list)
pilot_overlay_sent = np.zeros((pilotOverlayCodeLength,len(vis_list1)))
m = 0
for j in vis_list1 :
    pilot_overlay_sent[:,m] = l1.genNavicCaCode_Pilot_Overlay(j) # get the pilot overlay code for the satellite
    m += 1
    
#pilot_overlay_sent = pilotOverlayCodegen.GetBitStream()
print("pilot overlay shape=",pilot_overlay_sent.shape)

print("Visible satellites\n",satVis)
for i in range(satVis):
    
    
    # Find the index for which the lock counter is 20, after reaching a max lock counter value 
    # or index of max counter value less than 20
    max = 0
    maxval_lock_counter_idx = np.argmax(lock_fail_counter[:,i])
    maxval_lock_counter = lock_fail_counter[maxval_lock_counter_idx,i]
    print ("Maximum locked index is ", maxval_lock_counter_idx, maxval_lock_counter)
    if (maxval_lock_counter <= lock_counter_threshold):
        locked_sample_index = maxval_lock_counter_idx
        print ("Outer if: my locked index is ", maxval_lock_counter_idx, maxval_lock_counter)
        lckdidx = maxval_lock_counter_idx
    else :
        for idx in range(k) :
            if (max > lock_fail_counter [idx,i] and lock_fail_counter [idx,i] == lock_counter_threshold):
                locked_sample_index = idx
                print ("Inner if my locked index is ", idx, lock_fail_counter [idx,i])
                lckdidx = idx
                break
            else :
                max = lock_fail_counter [idx,i]
    
    #print(lckdidx)
    n = 1 #Number of data per bit
    skip = 0 #Forgo few bits as the tracking loops starts early
    #k = np.real(y_data[n*skip:,i])
    databits_received = np.real(y_data[n*skip:,i])
    pilotOverlay_received = np.imag(y_pilot[n*skip:,i])
    #print("DATABITS RECIEVED:",databits_received) 
    
    #
    #l = np.mean(k[sync_index:(((len(k)-sync_index)//n) * n) + sync_index].reshape(-1,n).T, axis=0)
    mapbits = lambda l: np.piecewise(l, [l < 0, l >= 0], [1, 0])
    mapbits_inverted = lambda l: np.piecewise(l, [l < 0, l >= 0], [0, 1])
    bits = mapbits(databits_received)
    overlay = mapbits(pilotOverlay_received)
    print("bits shape", len(bits))
    print("overlay shape", len(overlay))
    
    bits_inverted = mapbits_inverted(databits_received)
    overlay_inverted = mapbits_inverted(pilotOverlay_received)
    print("satellite=",i)
    num_sf = len(bits)//600
    
    for iter in range(k) :
            print("iter=", iter,  "data recd=",bits[iter], "overlay sent=", pilot_overlay_sent[iter,i],"overlay recd=",overlay[iter], pilot_overlay_sent[iter,i]==overlay[iter], fc[iter,i], coarse_delay[iter,i],fine_delay[iter,i],lock_fail_counter[iter,i]  )
            print("iter=", iter,  "data recd=",bits_inverted[iter], "overlay sent=", pilot_overlay_sent[iter,i],"overlay recd=",overlay_inverted[iter], pilot_overlay_sent[iter,i]==overlay_inverted[iter], fc[iter,i], coarse_delay[iter,i],fine_delay[iter,i],lock_fail_counter[iter,i]  )

    np.set_printoptions(threshold=np.inf)
    decode=l1.decoder()
    
    #print("Bits shape is:",bits.shape)
    if(pilot_overlay_sent[lckdidx,i]!=overlay[lckdidx]):
        s1_decoded,s2_decoded,s3_decoded=decode.subframes_decode(bits)
        print("Subframe1 After Receiving (52 Symbols):",bits[:52])
        print("Subframe1 After decoding (9 bits):",s1_decoded)
        print("Subframe2 After Receiving (1200 Symbols):",bits[52:1252])
        print("Subframe2 After decoding (600 bits):",s2_decoded)
        
        #test code for crc

        subframe2_decoded_string = ''.join(str(x) for x in s2_decoded)
        subframe2_decoded_int = int(subframe2_decoded_string,2)
        subframe2_decoded_hex= hex(subframe2_decoded_int)
        sub = ''.join(str(e) for e in subframe2_decoded_hex)
        subframe2decodedint = int(sub,16)
        
        decode.printlongdiv(subframe2decodedint, 25578747)
 
        print("Subframe3 After Receiving (548 Symbols):",bits[1252:])
        print("Subframe3 After decoding (274 bits):",s3_decoded)
        
        #test code for crc

        subframe3_decoded_string = ''.join(str(x) for x in s3_decoded)
        subframe3_decoded_int = int(subframe3_decoded_string,2)
        subframe3_decoded_hex= hex(subframe3_decoded_int)
        sub3 = ''.join(str(e) for e in subframe3_decoded_hex)
        subframe3decodedint = int(sub3,16)
        
        decode.printlongdiv(subframe3decodedint, 25578747)
 
 
    else:

        s1_decoded,s2_decoded,s3_decoded=decode.subframes_decode(bits_inverted)
        print("Subframe1 After Receiving (52 Symbols):",bits_inverted[:52])
        print("Subframe1 After decoding (9 bits):",s1_decoded)
        print("Subframe2 After Receiving (1200 Symbols):",bits_inverted[52:1252])
        print("Subframe2 After decoding (600 bits):",s2_decoded)
        
          
        subframe2_decoded_string = ''.join(str(x) for x in s2_decoded)
        subframe2_decoded_int = int(subframe2_decoded_string,2)
        subframe2_decoded_hex= hex(subframe2_decoded_int)
        sub = ''.join(str(e) for e in subframe2_decoded_hex)
        subframe2decodedint = int(sub,16)

        decode.printlongdiv(subframe2decodedint, 25578747)
        

        print("Subframe3 After Receiving (548 Symbols):",bits_inverted[1252:])
        print("Subframe3 After decoding (274 bits):",s3_decoded)
        
        subframe3_decoded_string = ''.join(str(x) for x in s3_decoded)
        subframe3_decoded_int = int(subframe3_decoded_string,2)
        subframe3_decoded_hex= hex(subframe3_decoded_int)
        sub3 = ''.join(str(e) for e in subframe3_decoded_hex)
        subframe3decodedint = int(sub3,16)
        
        decode.printlongdiv(subframe3decodedint, 25578747)
    
    print("k=", k)
    
    plt.subplot(6,1,1)
    plt.plot(fqyerr[:,i])
    #plt.ylim([0,0.05])
    plt.xlabel('time') ; plt.ylabel('Fqy Error')
    
    plt.subplot(6,1,2)
    plt.plot(fqynco[:,i])
    #plt.ylim([0,0.05])
    plt.xlabel('time') ; plt.ylabel('Fqy NCO')

    plt.subplot(6,1,3)
    plt.plot(pherr[:,i])
    #plt.ylim([0,0.05])
    plt.xlabel('time') ; plt.ylabel('Phase Error')

    plt.subplot(6,1,4)
    plt.plot(phnco[:,i])
    #plt.ylim([0,0.05])
    plt.xlabel('time') ; plt.ylabel('Phase NCO')

    plt.subplot(6,1,5)
    plt.plot(delayerr[:,i])
    #plt.ylim([0,0.05])
    plt.xlabel('time') ; plt.ylabel('Delay Error')
    
    plt.subplot(6,1,6)
    plt.plot(delaynco[:,i])
    #plt.ylim([0,0.05])
    plt.xlabel('time') ; plt.ylabel('Delay NCO')
    
    
    plt.savefig('./myplot.png')
    plt.show()

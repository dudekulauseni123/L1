import numpy as np
from fractions import Fraction
import math
import scipy.constants as sciconst
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
class NavicL5sModulator():
    def __init__(self, fs):
        self.sampleRate = fs
        self.codePhase = 0
        self.prnstart = 0
        self.cstart = 0

        # BOC(m,n) Init
        self.m1 = 1; self.n = 1
        self.m2 = 6
        fsc1 = self.m1*1.023e6
        epsilon1 = fsc1*1/(100*self.sampleRate)
        self.subCarrPhase1 = epsilon1 
        fsc2 = self.m2*1.023e6
        epsilon2 = fsc2*1/(100*self.sampleRate)
        self.subCarrPhase2 = epsilon2
        
    # columns of x have samples
    # columns of codeTable have sampled PRN sequence 
    def Modulate(self, x, codeTable1,codeTable2,codeTable3):

        codeNumSample_data = codeTable1.shape[0]
        codeNumSample_pilot = codeTable2.shape[0]
       
        
        numSample = x.shape[0]
        numChannel = x.shape[1]
        
        codeTable_p = codeTable2[(self.prnstart+np.arange(numSample))%codeNumSample_pilot]
        
        self.prnstart = ( self.prnstart+numSample)%codeNumSample_pilot
        
        # Subcarrier generation for BOC
        subCarr1Ch1 = self.__GenBocSubCarrier(numSample, self.m1)
        subCarr1Ch2 = self.__GenBocSubCarrier(numSample, self.m2)
        
        
        SubCarrSig1 = np.tile(np.array([subCarr1Ch1]).T, (1, numChannel))
        SubCarrSig2 = np.tile(np.array([subCarr1Ch2]).T, (1, numChannel))
        
        
        # PRN sequence of of pilot
        PilotCode = (codeTable_p+codeTable3)%2
        PilotSig = 1-2*PilotCode
        # Data 
        DataSig =1-2*np.logical_xor(x, codeTable1[np.arange(self.codePhase, self.codePhase+numSample)%codeNumSample_data, :])
        
        


        BocPilotSig1 = PilotSig * SubCarrSig1
        BocDataSig1 = DataSig * SubCarrSig1
        BocPilotsig6 = PilotSig * SubCarrSig2
    

        interplexSig = BocPilotSig1* BocDataSig1 *  BocPilotsig6

        self.codePhase = (self.codePhase+numSample)%codeNumSample_data

        alpha = (6/11)**0.5
        beta = (4/110)**0.5
        gamma = (4/11)**0.5
        eeta = (6/110)**0.5
        iqsig = (alpha*(BocPilotSig1)-beta* (BocPilotsig6 )) + 1j*(gamma*BocDataSig1+eeta*interplexSig)  # Document formula
        
        #iqsig = (alpha*(BocDataSig1)-beta* (interplexSig )) + 1j*(gamma*BocPilotSig1+eeta*BocPilotsig6)  # Document formula
        

        return iqsig
    
    def __GenBocSubCarrier(self, N, m):
        ts = 1/self.sampleRate
        t = np.arange(N)*ts
        fsc = m*1.023e6
         
        if(m == 1):
            #subCarrier = np.sign(np.sin(2*np.pi*(fsc*t + self.subCarrPhase1)))
            subCarrier = np.sign(np.sin(2*np.pi*fsc*t + self.subCarrPhase1))
            self.subCarrPhase1 += fsc*N*ts
            self.subCarrPhase1 -= int(self.subCarrPhase1)
        if(m == 6):
            #subCarrier = np.sign(np.sin(2*np.pi*(fsc*t + self.subCarrPhase2)))
            subCarrier = np.sign(np.sin(2*np.pi*fsc*t + self.subCarrPhase2))
            self.subCarrPhase2 += fsc*N*ts
            self.subCarrPhase2 -= int(self.subCarrPhase2)
        return subCarrier
    
    def Release(self,m):
        self.codePhase = 0

        fsc = m*1.023e6
        epsilon = fsc*1/(100*self.sampleRate)
        self.subCarrPhase = epsilon
        
'''        
# Define the number of samples and channels
num_samples = 100
num_channels = 2

# Generate dummy input data (x, codeTable1, codeTable2, codeTable3)
codeNumSample_data = 1023  # Define the appropriate value for codeNumSample_data
codeNumSample_pilot = 1023  # Define the appropriate value for codeNumSample_pilot

x = np.random.randint(0, 2, size=(num_samples, num_channels))
codeTable1 = np.random.randint(0, 2, size=(codeNumSample_data, num_channels))
codeTable2 = np.random.randint(0, 2, size=(codeNumSample_pilot, num_channels))
# Ensure codeTable3 has the same shape as codeTable_p
# Define the shape of codeTable3 to match the required dimensions
# Resize codeTable3 to match the shape of codeTable_p
codeTable3 = np.resize(codeTable3, codeTable_p.shape)

# Define codeTable3 with the correct shape
codeTable3_shape = (codeNumSample_pilot, num_channels)
codeTable3 = np.random.randint(0, 2, size=codeTable3_shape)



# Now codeTable3 has the same shape as codeTable_p

#codeTable3 = np.random.randint(0, 2, size=(codeNumSample_pilot, num_channels))

# Create an instance of the NavicL5sModulator class with a specific sample rate (fs)
sample_rate = 10e6  # 10 MHz sample rate for example
modulator = NavicL5sModulator(sample_rate)

# Modulate the input data using the Modulate method of the NavicL5sModulator class
iqsig = modulator.Modulate(x, codeTable1, codeTable2, codeTable3)

# Print the real and imaginary parts of the modulated signal
# Print the real and imaginary parts of the modulated signal
for i in range(num_samples):
    for j in range(num_channels):
        # Check if the index is within the bounds of iqsig array
        if i * num_channels + j < len(iqsig):
            print(f"({iqsig[i * num_channels + j].real}, {iqsig[i * num_channels + j].imag}) ", end="")
        else:
            print("(Index out of bounds)", end="")
    print()  # Print a new line after each row of complex numbers
    '''
    # Define the number of samples and channels
# Define the number of samples and channels
num_samples = 40e6
num_channels = 2

# Generate dummy input data (x, codeTable1, codeTable2, codeTable3)
x = np.random.randint(0, 2, size=(num_samples, num_channels))
codeNumSample_data = 1023
codeNumSample_pilot = 1023
codeTable1 = np.random.randint(0, 2, size=(codeNumSample_data, num_channels))
codeTable2 = np.random.randint(0, 2, size=(codeNumSample_pilot, num_channels))

# Define codeTable3 with the correct shape
codeTable3_shape = (codeNumSample_pilot, num_channels)
codeTable3 = np.random.randint(0, 2, size=codeTable3_shape)

# Resize codeTable3 to match the shape of codeTable1
codeTable3 = np.resize(codeTable3, codeTable1.shape)

# Create an instance of the NavicL5sModulator class with a specific sample rate (fs)
sample_rate = 10e6  # 10 MHz sample rate for example
modulator = NavicL5sModulator(sample_rate)

# Modulate the input data using the Modulate method of the NavicL5sModulator class
iqsig = modulator.Modulate(x, codeTable1, codeTable2, codeTable3)

# Print the real and imaginary parts of the modulated signal
for i in range(num_samples):
    for j in range(num_channels):
        # Check if the index is within the bounds of iqsig array
        if i * num_channels + j < len(iqsig):
            print(f"({iqsig[i * num_channels + j].real}, {iqsig[i * num_channels + j].imag}) ", end="")
        else:
            print("(Index out of bounds)", end="")
    print()  # Print a new line after each row of complex numbers




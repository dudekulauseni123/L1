import numpy as np

class BitGenerator:
    def __init__(self, numChannel, sampleRate, numSymbolsPerFrame, numSamplesPerBit):
        self.numChannel = numChannel
        self.sampleRate = sampleRate
        self.numSymbolsPerFrame = numSymbolsPerFrame
        self.numSamplesPerBit = numSamplesPerBit
        self.symbolStream = np.random.randint(0, 2, size=(1, self.numChannel))  # Initial random symbol stream
        self.bitcnt = 0
        self.samplesToNextBit = self.numSamplesPerBit

    #def SymbolsGen(self):
        # Implement your logic to generate symbols for a frame
        # This method is assumed to exist in your code

    def GenerateBits(self, timeInterval):
        genStream = np.empty((1, self.numChannel))
        numBitsToGen = round(self.sampleRate * timeInterval)
        bufferCnt = numBitsToGen

        while bufferCnt > 0:
            if bufferCnt < self.samplesToNextBit:
                genStream = np.append(genStream, np.repeat(self.symbolStream[self.bitcnt: self.bitcnt + 1, :], bufferCnt, axis=0), axis=0)
                self.samplesToNextBit -= bufferCnt
                bufferCnt = -1
            else:
                genStream = np.append(genStream, np.repeat(self.symbolStream[self.bitcnt: self.bitcnt + 1, :], self.samplesToNextBit, axis=0), axis=0)
                self.bitcnt += 1
                if self.bitcnt % self.numSymbolsPerFrame == 0:
                    full_frame = np.empty(0)
                    full_data = np.empty(0)
                    for i in range(self.numChannel):
                        frame, data = self.SymbolsGen()
                        full_frame = np.append(full_frame, frame)
                        full_data = np.append(full_data, data)

                    self.symbolStream = np.append(self.symbolStream, full_frame.reshape(self.numChannel, -1).T, axis=0)
                    self.dataStream = np.append(self.dataStream, full_data.reshape(self.numChannel, -1).T, axis=0)

                bufferCnt -= self.samplesToNextBit
                self.samplesToNextBit = self.numSamplesPerBit

        return genStream[1:numBitsToGen + 1]

# Example Usage
numChannel = 2
sampleRate = 1000  # Assuming a sample rate of 1000 samples per second
numSymbolsPerFrame = 4
numSamplesPerBit = 10
timeInterval = 0.5  # 0.5 seconds

bit_generator = BitGenerator(numChannel, sampleRate, numSymbolsPerFrame, numSamplesPerBit)
generated_bits = bit_generator.GenerateBits(timeInterval)

print("Generated Bits:", generated_bits)


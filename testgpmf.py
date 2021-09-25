#import gpmf, sys
from gpmf.gpmf_bindings import GPMF
import sys
import PySide2
import matplotlib.pyplot as plt

myTest = GPMF("gopro6.mp4")
samples = myTest.getGyroscope()
time = []
z = []
x = []
y = []
for sample in samples:
    time.append(sample.time.value)
    z.append(sample.entries[0].value)
    x.append(sample.entries[1].value)
    y.append(sample.entries[2].value)
#myTest.exportGPStoGPX('GPSexport')

plt.plot(time, z)
#plt.plot(time, x)
#plt.plot(time, y)
plt.ylabel('z gyro')
plt.grid()
plt.show()

print('GPMF test Done !')

sys.exit(0)

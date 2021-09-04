#import gpmf, sys
from gpmf.gpmf_bindings import GPMF
import sys

myTest = GPMF("gopro6.mp4")
result = myTest.getGyroscope()
for sample in result:
    print('%s: %2.5f %s' % (sample.time.info, sample.time.value, sample.time.unit), end='')
    print(', %s: %2.5f %s' % (sample.duration.info, sample.duration.value, sample.duration.unit), end='')
    for entry in sample.entries:
        print(', %s: %2.5f %s' % (entry.info, entry.value, entry.unit), end='')
    print()
        
print('GPMF test Done !')


sys.exit(0)

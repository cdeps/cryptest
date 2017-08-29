# cdeps / cryptest

A self-made cryptography algorithm. This is an example implementation of the scheme idea's promoted [here](https://gist.github.com/finwo/ebfd96e35eeffc19dc25f5afc11b9c98). The algorithm HAS NOT been tested for actual cryptographic strength, do not assume this provides anything more than obfuscation.

---

Keys are composed of 2 unsigned 32-bit integers, the multiplicand and the modulator. The only restriction on these numbers is that the modulator must be >=128, which results in ((2^32)-128)*(2^32) = 18446743523953737728 possible keys. Padding is forced to further randomize the output and has no structural restrictions.

# NXTrim
# Language: C++
# Input: TXT
# Output: PREFIX
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: NXTrim

PluMA plugin to run NXTrim (O'Connell, 2015) adapter trimmer

The plugin accepts as input a TXT file containing the names of the FASTQ
files to check.

Trimmed sequences are output to FASTQ.GZ files using the output PREFIX

#!/bin/bash

set -e

ESDK=${EPIPHANY_HOME}
ELIBS=${ESDK}/tools/host/lib
EINCS=${ESDK}/tools/host/include
ELDF=${ESDK}/bsps/current/fast.ldf

SCRIPT=$(readlink -f "$0")
EXEPATH=$(dirname "$SCRIPT")
cd $EXEPATH

CROSS_PREFIX=
case $(uname -p) in
	arm*)
		# Use native arm compiler (no cross prefix)
		CROSS_PREFIX=
		;;
	   *)
		# Use cross compiler
		CROSS_PREFIX="arm-linux-gnueabihf-"
		;;
esac

mkdir -p Debug

# Build HOST side application
${CROSS_PREFIX}gcc -std=gnu99 -I. src/feldspar-parallella.c src/host.c -g -o Debug/host.elf -I ${EINCS} -L ${ELIBS} -le-hal -le-loader

# Build DEVICE side programs
e-gcc -std=gnu99 -T ${ELDF} -I. src/feldspar-parallella.c src/core0.c -g -o Debug/core0.elf -le-lib -D__epiphany__
e-gcc -std=gnu99 -T ${ELDF} -I. src/feldspar-parallella.c src/core1.c -g -o Debug/core1.elf -le-lib -D__epiphany__

# Convert ebinaries to SREC files
e-objcopy --srec-forceS3 --output-target srec Debug/core0.elf Debug/core0.srec
e-objcopy --srec-forceS3 --output-target srec Debug/core1.elf Debug/core1.srec

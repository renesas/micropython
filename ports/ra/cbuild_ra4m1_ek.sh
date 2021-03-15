#!/bin/bash
set -eu -o pipefail
export BOARD="RA4M1_EK"
DT=`date +%Y%m%d%H%M`
make DEBUG=1 BOARD=${BOARD}       2>&1 | tee -a ${BOARD}_build_${DT}.log

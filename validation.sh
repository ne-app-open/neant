#! /bin/sh

## To be used for curl -fsSL https://install.nekernel.org | sh

echo "==> NE.APP: WELCOME TO THE NESYSTEM VALIDATION PDK."
echo "==> NE.APP: INSTALLING PDK..."
echo "==> NEW: ANT IS NOW AVAILABLE AS A STANDALONE OS DISTRIBUTION AND PDK."

echo "==> COMING SOON: ANT AND NESYSTEM DRIVERS REPOSITORY WILL SOON BE AVAILABLE."

ARCH=x64
PROFILE=release-efi-pc

SRC=src
KRNL=krnl
NEBUILD=bld
NCC=ncc
FLAGS=clone
DIST=src-${ARCH}-${PROFILE}
GIT=git

mkdir ${DIST}

${GIT} ${FLAGS} https://github.com/ne-app-open/${SRC}.git --branch validation ${DIST}/${SRC}
${GIT} ${FLAGS} https://github.com/ne-app-open/${KRNL}.git --branch validation ${DIST}/${KRNL}
${GIT} ${FLAGS} https://github.com/ne-app-open/${NEBUILD}.git --branch validation ${DIST}/${NEBUILD}
${GIT} ${FLAGS} https://github.com/ne-app-open/${NCC}.git --branch validation ${DIST}/${NCC}

cd ${DIST}

echo "==> DONE."
@echo off

:: To be used for curl -fsSL https://setup.nekernel.org

echo "==> NE.APP: WELCOME TO THE NEANT CANARY PDK."
echo "==> NE.APP: INSTALLING PDK..."
echo "==> NEW: ANT IS NOW AVAILABLE AS A STANDALONE OS DISTRIBUTION AND PDK."

echo "==> COMING SOON: ANT AND NEANT DRIVERS REPOSITORY WILL SOON BE AVAILABLE."

set ARCH=x64
set PROFILE=release-efi-pc

set SRC=src
set KRNL=krnl
set NEBUILD=bld
set VCS=git
set NCC=ncc
set FLAGS=clone
set DIST=src-%ARCH%-%PROFILE%

mkdir %DIST%

%VCS% %FLAGS% https://github.com/ne-app-open/%SRC%.git %DIST%\%SRC%
%VCS% %FLAGS% https://github.com/ne-app-open/%KRNL%.git %DIST%\%KRNL%
%VCS% %FLAGS% https://github.com/ne-app-open/%NEBUILD%.git %DIST%\%NEBUILD%
%VCS% %FLAGS% https://github.com/ne-app-open/%NCC%.git -b stable %DIST%\%NCC%

cd %DIST%

echo "==> DONE."
